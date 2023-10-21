# knob.h

knob.h is a single-header library that serves as a way to build your C projects with a C executable.

As simple as(cc == your c compiler):
```console
$ cc ./knob.c -o knob
$ ./knob
```

## Examples:
To test out the examples in vscode, modify the `tasks.json` and `launch.json` to specify the directory to the example you are testing.
`launch.json`:
```json
    {
    "name": "(knob) Launch",
    // ...
    "cwd": "${workspaceRoot}/examples/submodule",
    //...
    }
```
`tasks.json`:
```json
{
    "label": "Build knob",
    //...
    "args": [
        //...
        "${workspaceFolder}/examples/submodule/knob.c",
        //...
    ],
},
```

## Acknowledgements

Much thanks goes to [rexim](github.com/tsoding) on making [nob](https://github.com/tsoding/musializer/blob/master/src/nob.h) and [nobuild](https://github.com/tsoding/nobuild), the first iterations upon which knob is built.
