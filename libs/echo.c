#include "/home/codeleaded/System/Static/Library/DLL.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"

void* echo(Process* p){
    if(p->args.size == 2){
        Process_Write_Stdout(p,*(char**)Vector_Get(&p->args,1));
    }else{
        Process_Write_Stdout(p,"echo: Error because echo expected 2 args but got 0 or 3+\n");
    }
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("echo",echo));
}
