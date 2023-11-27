#define KNOB_IMPLEMENTATION
#include "knob.h"

// WARNING /////////////////////////////////////////////
// When using SUBMODULE's on Linux, don't compile knob.c
// with musl. SUBMODULE's need dynamic loading and musl
// doesn't allow it. On Alpine you might be able to
// simply link with libdl and load the dynamic lib. 
////////////////////////////////////////////////////////

MAIN(test){
    Knob_Config config = {0};
    knob_compute_default_config(&config);
    config.compiler = COMPILER_ZIG;
    Knob_Cmd cmd = {0};
    // START Compile submodule
    Knob_File_Paths object_files = {0};
    Knob_Cmd pass_cmds = {0};
    char* path_to_knobh = "../..";
    knob_compile_run_submodule("../basic",&config,&object_files,&pass_cmds,path_to_knobh);
    for(int i =0; i < object_files.count;++i){
        char* temp = object_files.items[i];
        knob_log(KNOB_INFO,"%s",temp);
        continue;
    }
    // END Compile submodule

    return 0;

    knob_cmd_append(&cmd,"./examples/submodule/main.c");
    knob_cmd_append(&cmd,"-o", "sailor");
    

    knob_cmd_run_sync(cmd);
    cmd.count = 0;
    knob_cmd_append(&cmd,"./sailor");
    knob_cmd_run_sync(cmd);

}