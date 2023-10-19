- [ ] Bring compiler setting logic from nob.c files of rexim.
- [ ] Add ability to add submodules(i.e. they are dll's that we can use from other knob.c files)
    - [ ] Add a MAIN define that changes when we build the file as a SUBMODULE
- [ ] Add IDE project generation(for smooth brained apes like me)
    - [ ] Visual Studio
    - [ ] Vscode
    - [ ] Others from non windows platforms
- [ ] Add "easier" API like kmake

## Examples:
- [ ] Add a basic hello world example
- [ ] Add a raylib build example
- [ ] Add a submodule build example
- [ ] Add a wasm based website blog generator using [md4c](https://github.com/mity/md4c)
    - [ ] For zig target use: `zig cc hello.c -target wasm32-wasi`