#include "/home/codeleaded/System/Static/Library/DLL.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"

void* ls(Process* p){
    Shell* sh = (Shell*)p->parent;

    if(p->args.size == 1){
        CStr path = CStr_Format("%s/%s",sh->Root,sh->Path);
        CStr cpath = Files_CompressPath(path);

        String_Appendf(&p->stream_stdout,"ls: in directory: %s\n",cpath);
        Vec_CStr childs = Files_GetChilds(cpath);

        if(childs.size == 0){
            String_Appendf(&p->stream_stdout,"empty directory\n");
        }

        for(int i = 0;i<childs.size;i++){
            CStr child = *(CStr*)Vector_Get(&childs,i);
            CStr name = Files_NameFull(child);
            String_Appendf(&p->stream_stdout,"|- %s\n",name);
            CStr_Free(&name);
        }

        Vec_CStr_Free(&childs);
        CStr_Free(&cpath);
        CStr_Free(&path);
    }else{
        Process_Write_Stdout(p,"ls: Error because ls got invalid args!\n");
    }
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("ls",ls));
}
