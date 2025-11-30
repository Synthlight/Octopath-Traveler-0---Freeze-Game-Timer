# Primary description, updates, everything, are on Nexus. What's here is just a copy from there. I will probably neglect this readme unless it gets removed from Nexus.

# [Freeze the Game Timer (For Demo) | On Nexus Mods](https://www.nexusmods.com/octopathtraveler0/mods/4)

The rest is mostly copy/paste from there:<br>
<br>
<br>
<br>

Freezes the save timer to whatever it is when you last saved.<br>
(I have no tested to see what happens when you create a *new* game with this installed. With this added after the fact though, the save timer just never advances. So, presumably, a new save would just be stuck at 0:00:00?)

I see no legal or moral issue with a mod like this. (You aren't getting access to additional content, you just aren't being forced to make a new save every 3 hours.)<br>
If it gets removed from there, it'll stay available here.<br>
I will probably not be updating this after the game releases, and may even hide the mod there after it does.

Whatever Antivirus you're using may flag this given how it works. There's nothing I can do about that, that's on you to deal with/bypass. You can click the green checkmark on literally any file on Nexus to see the VirusTotal scan results of any given file.

# Installing
---
Pick one method. The ASI loader option is required if you want to use multiple mods that work this way.
 - Directly, as `winhttp.dll` (i.e. No ASI Loader):
   - Extract **directly** into `Octopath_Traveler0\Binaries\Win64`.
   - **RENAME THE FILE TO `winhttp.dll`!** (And make SURE you extensions aren't hidden so you don't wind up with `winhttp.dll.asi`.)
 - With an ASI loader:
   - Install an ASI loader such as [this](https://github.com/ThirteenAG/Ultimate-ASI-Loader).
     - You want the x64 build, winhttp.dll.
     - Direct link: [https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases/download/x64-latest/winhttp-x64.zip](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases/download/x64-latest/winhttp-x64.zip)
     - **Do not put it directly in the game root dir**, place it in `Octopath_Traveler0\Binaries\Win64`. Essentially, you install the loader the same way you would as if you were using this mod directly, as `winhttp.dll`.
   - Extract into `Octopath_Traveler0\Binaries\Win64\plugins`.
   - That's it. I used to do mods like this with the mod released as `winhttp.dll` but people proved how 'challenged' they were at renaming and placing it directly, so now it's an ASI by default.

# Troubleshooting
---
When this runs (when it's loaded) it creates a log file with the same as whatever the DLL/ASI is named; the extension is just changed to LOG.<br>
If the log isn't being created when you launch the game then you've installed it wrong.<br>
If the effect isn't working, first close the game, delete the log file, and launch the game again to confirm it is still being loaded.<br>
After that, open the log and confirm patching was done successfully.<br>
If, for some reason patching fails, this will create a little window/prompt to say such.<br>
**If you still need help after, GIVE ME THE LOG FILE!!!!**

# Uninstalling
Nothing special. Delete files.

# Conflicts
Will only conflict, by name, with other DLL proxies installed directly as `winhttp.dll`. Use the ASI loader in such a case.

# Made for the demo. Will update for the full game when I can, have patience.