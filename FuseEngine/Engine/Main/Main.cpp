#include "../Editor/EditorWindow/Editor.h"
#include "../Editor/Window/Window.h"

int main()
{
	FuseEngine::Window window;
	FuseEngine::Editor editor;

	window.SetEditor(editor);
	window.SetupWindow();
	window.MainWindowLoop();

	return 0;
}