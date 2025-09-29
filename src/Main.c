//#define IMAGE_PNG_ONLY

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/Shell.h"


Shell shell;

void Setup(AlxWindow* w){
	SetAlxFont(AlxFont_HIGH);

	shell = Shell_New("Root","~","./bin/",GetWidth(),GetHeight());
}
void Update(AlxWindow* w){
	Shell_Update(&shell,w->Strokes,(Vec2){ w->MouseX,w->MouseY });

	if(Stroke(ALX_KEY_ENTER).PRESSED)
		Shell_Execute(&shell);

	if(Stroke(ALX_KEY_CTRL).DOWN && Stroke(ALX_KEY_C).PRESSED)
		Shell_Signal_Int(&shell);

	Clear(BLACK);

	Shell_Render(WINDOW_STD_ARGS,&shell);

	//String str = String_Format("S:%d,%d",window.Width,window.Height);
	//CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,0.0f,WHITE);
	//String_Free(&str);
}
void Delete(AlxWindow* w){
	Shell_Free(&shell);
}

int main(){
    if(Create("Mario",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}