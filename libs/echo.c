#include "/home/codeleaded/System/Static/Library/DLL.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"

void* echo(Process* p){
    Process_Write_Stdout(p,"Hello World\n");
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("echo",echo));
}
