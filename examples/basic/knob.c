#define KNOB_IMPLEMENTATION
#include "../../knob.h"


MAIN(basic){
    Knob_Cmd cmd = {0};
    knob_cmd_append(&cmd, "zig","cc");
    knob_cmd_append(&cmd, "-static");
    knob_cmd_append(&cmd, "--debug", "-std=c11", "-fno-sanitize=undefined","-fno-omit-frame-pointer");
    knob_cmd_append(&cmd, "-target");
    knob_cmd_append(&cmd, "x86_64-linux-musl");
    knob_cmd_append(&cmd,"main.c");
    #ifdef KNOB_SUBMODULE
    knob_cmd_append(&cmd,"-o", "sailor.o");
    knob_cmd_append(basic_link_files,"sailor.o");
    #else
    knob_cmd_append(&cmd,"-o", "sailor");
    #endif

    knob_cmd_run_sync(cmd);
    #if !defined(KNOB_SUBMODULE)
    cmd.count = 0;
    knob_cmd_append(&cmd,"./sailor");
    knob_cmd_run_sync(cmd);
    #endif

    return 0;
}