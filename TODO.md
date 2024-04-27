- [X] Add ability to add submodules(i.e. they are dll's that we can use from other knob.c files)
    - [X] Add a MAIN define that changes when we build the file as a SUBMODULE
- [X] Bring compiler setting logic from nob.c files of rexim.
- [ ] Add "easier" API like kmake
    - [X] Add includes
    - [X] Add c/cpp_flags
    - [X] Add defines
    - [X] Add C/C++ files to compile
    - [X] Use Kinc tools
    - [X] Add example usage
    - [ ] Add IDE project generation(for smooth brained apes like me)
        - [ ] Visual Studio
        - [ ] Vscode compile_commands.json
        - [ ] Others from non windows platforms

- [ ] Add automatic builds and tests on github.

- [ ] Make a Kinc knob.c submodule to replace the use with kmake

- [ ] Add dependency getting like [zig](https://youtu.be/wFlyUzUVFhw?si=W7TwcVLrplQG3EFs&t=2187)
    - [ ] Implement a way to fetch data online.

## Examples:
- [X] Add a basic hello world example
- [X] Add a submodule build example
- [ ] Add a raylib build example
- [ ] Add a Kinc build example
- [ ] Add a wasm based website blog generator using [md4c](https://github.com/mity/md4c)
    - [ ] Generate [js](https://github.com/michaelfranzl/clang-wasm-browser-starterpack/tree/dev) to [interop](https://dev.to/begoon/compile-c-to-webassembly-wasm-and-run-it-in-the-browser-h1l)
    - [ ] For zig target use: `zig cc hello.c -target wasm32-wasi`