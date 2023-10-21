
#include <stdio.h>

#ifdef IS_DLL
int call_sailor(void)
#else
int main(int argc, char** argv)
#endif
{
    printf("Hello Sailor !\n");
    return 0;
}