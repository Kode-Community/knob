#define KNOB_IMPLEMENTATION
#include "../../knob.h"

MAIN(KMAKE_LIKE){

    if(!knob_mkdir_if_not_exists("build")){ return 1;}
    if(!knob_mkdir_if_not_exists("Deployment")){ return 1;}

    Knob_Cmd cmd = {0};
    //FETCH the Tools
    if(!knob_mkdir_if_not_exists("Tools")){ return 1;}

    #ifdef _WIN32
    #define PLATFORM "windows_x64"
    const char* kraffiti_path = "./Tools/kraffiti.exe";
    #elif __linux__
    #define PLATFORM "linux_x64"
    const char* kraffiti_path = "./Tools/kraffiti";
    #else
    const char* kraffiti_path = "./Tools/kraffiti";
    #define PLATFORM "freebsd_x64"
    #endif

    if(!knob_file_exists(kraffiti_path)){
        knob_cmd_append(&cmd,"git","clone","https://github.com/Kode/KincTools_"PLATFORM".git","./Tools");

        if(!knob_cmd_run_sync(cmd)) return 1;
    }

    cmd.count = 0;
    knob_log(KNOB_INFO,"Running kraffiti...");
    knob_cmd_append(&cmd,kraffiti_path,"from=./Tools/icon.png","to=./Deployment/output.png","width=64","height=64");
    if(!knob_cmd_run_sync(cmd)) return 1;
    cmd.count = 0;


    Knob_Config config = {0};
    knob_config_init(&config);
    config.compiler = COMPILER_ZIG;

    knob_config_add_define(&config,"-DKINC_MAYBE");

    Knob_File_Paths files = {0};
    //@TODO: We need to support Sources/** and Sources/*, eventually.
    knob_da_mult_append(&files,
        "Sources/mycpp.cpp",
        "Sources/test.c",
        "Sources/main.c"
    );
    config.build_to = "."PATH_SEP"build";
    knob_config_add_files(&config,files.items,files.count);

    files.count = 0;
    knob_da_mult_append(&files,
        "./Sources"
    );
    knob_config_add_includes(&config,files.items,files.count);

    Knob_File_Paths out_files = {0};
    // Right now we basically just build the files directly. Eventually it could be usefull to generate 
    // .sln and/or compile_commands.json.
    if(!knob_config_build(&config,&out_files)) return 1;

    cmd.count = 0;

    knob_cmd_add_compiler(&cmd,&config);

    for(int i =0; i < out_files.count;++i){
        knob_cmd_append(&cmd,out_files.items[i]);
    }
    knob_cmd_add_includes(&cmd,&config);

    knob_cmd_append(&cmd,"-o","./Deployment/kmakelike.com");
    knob_cmd_append(&cmd,"-lm");
    knob_cmd_append(&cmd,"-lstdc++");

    Knob_String_Builder render = {0};
    knob_cmd_render(cmd,&render);
    knob_log(KNOB_INFO,"CMD: %s",render.items);

    if(!knob_cmd_run_sync(cmd)) return 1;
    
    cmd.count = 0;

    //Just run the executable to show that we can run it with ease, usually you would run
    // it in the editor you fancy to debug your executable. 
    knob_cmd_append(&cmd,"./Deployment/kmakelike.com");
    if(!knob_cmd_run_sync(cmd)) return 1;
    return 0;

}