#include "/home/codeleaded/System/Static/Library/DLL.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"

void* cd(Process* p){
    Shell* sh = (Shell*)p->parent;

    if(p->args.size == 2){
        CStr path = CStr_Format("%s/%s",sh->Path,*(char**)Vector_Get(&p->args,1));
        CStr cpath = Files_CompressPath(path);
        CStr_Set(&sh->Path,cpath);
        CStr_Free(&cpath);
        CStr_Free(&path);
    }else{
        Process_Write_Stdout(p,"cd: Error because cd got invalid args!\n");
    }
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("cd",cd));
}
