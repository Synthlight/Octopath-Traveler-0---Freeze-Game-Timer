#include "pch.h"

#include "base-dllmain.h" // Don't forget to add `version.lib` to Linker -> Input -> Additional Dependencies. Linker will give you unresolved symbols without it.
#include "AllocateMemory.h"
#include "AoBSwap.h"
#include "Common.h"
#include "Logger.h"
#include "PatchThreading.h"
#include "Util.h"

BOOL APIENTRY DllMain(const HMODULE hModule, const DWORD ulReasonForCall, const LPVOID lpReserved) {
    SetupLog(GetLogPathAsCurrentDllDotLog());
    if (EndsWith(GetFullModulePath(), ".asi")) {
        EmptyDllProxy proxy;
        return BaseDllMain(hModule, ulReasonForCall, lpReserved, proxy);
    }
    WinHttpDllProxy proxy;
    return BaseDllMain(hModule, ulReasonForCall, lpReserved, proxy);
}

bool StopTheGameTimer(const std::string& moduleName, const PTR_SIZE moduleAddress, AllocateMemory* allocator, LogBuffer* logBuffer) {
    const auto newMemBytes = StringToByteVector("8B 87 70 04 00 00"); // add eax,[rdi+00000470] -> mov eax,[rdi+00000470]
    return DoSimplePatch(moduleName, moduleAddress, "Stop The Game Timer (ApplicationStateManager (+470, Timer, Int))", "03 87 70 04 00 00 3B C3", newMemBytes, logBuffer);
}

void DoInjection() {
    const auto moduleName   = "Octopath_Traveler0-Win64-Shipping.exe";
    const auto moduleHandle = GetModuleHandle(moduleName);

    if (moduleHandle == nullptr) {
        LOG("Unable to find module, aborting.");
        return;
    }

    const auto moduleAddress = reinterpret_cast<const PTR_SIZE>(moduleHandle);
    LOG("Module base address: " << std::uppercase << std::hex << moduleAddress);

    const auto moduleInfo = GetModuleInfo(GetCurrentProcess(), moduleHandle);
    LOG("Module size: " << std::uppercase << std::hex << moduleInfo.SizeOfImage);

    AllocateMemory allocator;
    if (!allocator.AllocateGlobalAddresses(moduleName, moduleAddress)) {
        MessageBoxW(nullptr, L"Patching failed.", L"Patching Failed", MB_ICONERROR | MB_OK);
        return;
    }

    const std::vector<PatchFunction> injectorFunctions{
        &StopTheGameTimer,
    };

    const auto result = DoPatchFunctionsAsync(moduleName, moduleAddress, &allocator, injectorFunctions);

    LOG("");

    if (result) {
        //MessageBoxW(nullptr, L"Patching done!", L"Patching Done", MB_ICONINFORMATION | MB_OK);
    } else {
        MessageBoxW(nullptr, L"Patching failed.", L"Patching Failed", MB_ICONERROR | MB_OK);
    }

    LOG("Patching done!");
}