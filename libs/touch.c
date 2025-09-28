#include "/home/codeleaded/System/Static/Library/DLL.h"

int touch(void* arg,int argc,char** argv){
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("touch",touch));
}
