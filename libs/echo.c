#include "/home/codeleaded/System/Static/Library/DLL.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"

void* echo(Process* p){
    Shell* sh = (Shell*)p->parent;

    if(p->args.size == 2){
        Process_Write_Stdout(p,*(char**)Vector_Get(&p->args,1));
        Process_Write_Stdout(p,"\n");
    }else if(p->args.size == 4){
        CStr path = CStr_Format("%s/%s",sh->Root,*(char**)Vector_Get(&p->args,3));
        CStr rpath = CStr_Format("%s/%s/%s",sh->Root,sh->Path,*(char**)Vector_Get(&p->args,3));
        CStr cpath = Files_CompressPath(path);
        CStr crpath = Files_CompressPath(rpath);

        CStr usedpath = Files_isFile(crpath) ? crpath : (Files_isFile(cpath) ? cpath : NULL);

        if(!usedpath){
            Process_Write_Stdout(p,"echo: Error because echo got invalid path!\n");
        }else if(CStr_Cmp(*(char**)Vector_Get(&p->args,2),">")){
            Files_WriteT(
                usedpath,
                *(char**)Vector_Get(&p->args,1),
                CStr_Size(*(char**)Vector_Get(&p->args,1))
            );
        }else if(CStr_Cmp(*(char**)Vector_Get(&p->args,2),">>")){
            Files_AppendT(
                usedpath,
                *(char**)Vector_Get(&p->args,1),
                CStr_Size(*(char**)Vector_Get(&p->args,1))
            );
        }else{
            Process_Write_Stdout(p,"echo: Error because echo got invalid args!\n");
        }

        CStr_Free(&crpath);
        CStr_Free(&cpath);
        CStr_Free(&rpath);
        CStr_Free(&path);
    }else{
        Process_Write_Stdout(p,"echo: Error because echo got invalid args!\n");
    }
    return 0;
}

void Ex_Packer(DLLPackage* pack){
    DLLPackage_Add(pack,DLLFunction_New("echo",echo));
}
