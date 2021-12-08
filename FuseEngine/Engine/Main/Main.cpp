#include "../Editor/EditorWindow/Editor.h"
#include "../Editor/Window/Window.h"

int main()
{
	FuseEngine::Editor editor;
	FuseEngine::Window window(editor);

	window.Initialise();
	window.MainWindowLoop();

	return 0;
}