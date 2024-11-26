## IIR Oscillator


### Win11 Build



Using VSCode and MSYS2-MINGW64

```
mkdir build
cd build
cmake ../
cmake --build .
```



```bash
# In MSYS2 shell
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
pacman -S --needed mingw-w64-x86_64-cmake
```

The edit `%UserProfile%\AppData\Roaming\Code\User\settings.json`
```json
{
    ...
    "cmake.environment": {
        "MSYSTEM": "MINGW64",
        "MSYSTEM_PREFIX": "C:/msys64/mingw64",
        "PATH": "C:/msys64/mingw64/bin"
    },
    "cmake.generator": "MSYS Makefiles",
    "cmake.loggingLevel": "debug",
    "cmake.configureSettings": {
        "CMAKE_AR": "C:/msys64/mingw64/bin/ar.exe",
        "CMAKE_MAKE_PROGRAM": "C:/msys64/usr/bin/make.exe",
        "CMAKE_PREFIX_PATH": "C:/msys64/mingw64",
    },
    "terminal.integrated.defaultProfile.windows": "bash (MSYS2)",
    "terminal.integrated.profiles.windows": {
        ...
        "bash (MSYS2)": {
            "path": "C:/msys64/usr/bin/bash.exe",
            "args": [
                "--login",
                "-i"
            ],
            "env": {
                "MSYSTEM": "MINGW64",
                "CHERE_INVOKING": "1"
            }
        }
    }
}

```

* https://code.visualstudio.com/docs/cpp/config-mingw
* https://medium.com/@ahmetekiz/how-to-compile-c-in-vscode-on-windows-11-11518b471c68
* https://www.msys2.org/docs/cmake/
