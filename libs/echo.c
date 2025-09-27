#include "/home/codeleaded/System/Static/Library/DLL.h"

int echo(int argc,char** argv){
    //print in Terminal or stdout create process with String fd 0,1,2
    return 69;
}

void Ex_Packer(DLLPackage* pack){//Vector<int(*)(int,char**)>
    DLLPackage_Add(pack,DLLFunction_New("echo",echo));
}
