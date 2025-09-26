//#define IMAGE_PNG_ONLY

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"


void Setup(AlxWindow* w){
	AlxFont_Resize(&window.AlxFont,16,16);

}
void Update(AlxWindow* w){
	

	Clear(LIGHT_BLUE);

	String str = String_Format("S:%d,%d",window.Width,window.Height);
	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,0.0f,WHITE);
	String_Free(&str);
}
void Delete(AlxWindow* w){
	
}

int main(){
    if(Create("Mario",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}