#define KNOB_IMPLEMENTATION
#include "knob.h"


MAIN(test){
    Knob_Cmd cmd = {0};
    // START Compile submodule
    Knob_Cmd files_to_link = {0};
    Knob_Cmd pass_cmds = {0};
    knob_compile_run_submodule("../basic",&files_to_link,&pass_cmds);
    for(int i =0; i < files_to_link.count;++i){
        char* temp = files_to_link.items[i];
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