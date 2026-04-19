# RP6502 VSCode Scaffolding for LLVM-MOS

This is scaffolding for a new Picocomputer 6502 software project.

### LLVM PATH notes

LLVM-MOS must be in your PATH. However, this may conflict with other LLVM
installations, like the one that comes with your operating system.
In that case, you can adjust the path for only CMake with a VSCode setting.
Add a file `.vscode/settings.json` with the following contents. Adjust the
path for where you installed LLVM-MOS.
```
{
    "cmake.environment": {
        "PATH": "~/llvm-mos/bin:${env:PATH}"
    }
}
```

### Linux Tools Install:
 * [VSCode](https://code.visualstudio.com/). This has its own installer.
 * An install of [LLVM-MOS](https://llvm-mos.org/wiki/Welcome).
   See PATH notes above.
 * The following tools installed from your package manager:
    * `sudo apt install cmake python3 git build-essential`

### Windows Tools Install:
 * `winget install -e --id Microsoft.VisualStudioCode`
 * `winget install -e --id Git.Git`
 * `winget install -e --id Kitware.CMake`
 * `winget install -e --id GnuWin32.Make`.
    Add "C:\Program Files (x86)\GnuWin32\bin" to your path.
 * An install of [LLVM-MOS](https://llvm-mos.org/wiki/Welcome).
   See PATH notes above.
 * Install python by typing `python3` which will launch the Microsoft Store
   where you start the install. If python runs, this has already been done,
   exit python with Ctrl-Z plus Return.

### Getting Started:
Go to the [GitHub template](https://github.com/picocomputer/vscode-llvm-mos)
and select "Use this template" then "Create a new repository". GitHub will
make a clean project for you to start with. Then you can download the
repository and open the files.

```
$ git clone [path_to_github]
$ cd [to_where_it_cloned]
$ code .
```

Install the recommended extensions when VS Code prompts you, choosing the
default or obvious choice for any other prompts. The tools we use in VS Code
are constantly improving and have their own documentation. The first problem
you might encounter is that no kit is configured, so begin by reading this
and choosing the `[Unspecified]` kit:
https://code.visualstudio.com/docs/cpp/cmake-linux
The full documentation for the CMake plugin is here:
https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/README.md

"Start Debugging" (F5) will build your project and run it on a Picocomputer.
Connect with a USB cable plugged into the RP6502-VGA USB port.

If you get a Python error about the communications device not being found,
edit `.rp6502` in the project root. This file will be created the first time
you "Start Debugging" and will be ignored by git. You may also connect over
telnet by instead providing a hostname for the device and setting the key.

Once the program is running, a debug console becomes available on the terminal
tab. It will say "Python Debug Console" because the rp6502.py tool is Python.
Ctrl-A then X will exit. Ctrl-A then B will send a break.

Edit `CMakeLists.txt` to add new source and asset files. From here on, it's
standard C/C++/assembly development for the 6502 platform.
