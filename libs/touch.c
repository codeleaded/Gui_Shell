#include "/home/codeleaded/System/Static/Library/DLL.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"

void* touch(Process* p){
    Shell* sh = (Shell*)p->parent;

    if(p->args.size == 2){
        CStr rpath = CStr_Format("%s/%s/%s",sh->Root,sh->Path,*(char**)Vector_Get(&p->args,1));
        CStr crpath = Files_CompressPath(rpath);

        String_Appendf(&p->stream_stdout,"%s\n",crpath);
        Files_Create(crpath);

        CStr_Free(&crpath);
        CStr_Free(&rpath);
    }else{
        Process_Write_Stdout(p,"touch: Error because touch expected 2 args!\n");
    }
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("touch",touch));
}
