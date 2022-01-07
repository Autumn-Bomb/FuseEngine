#include "../Editor/EditorWindow/Editor.h"
#include "../Editor/Window/Window.h"

int main()
{
	srand(time(NULL));

	Fuse::Editor editor;
	Fuse::Window window(editor);

	window.Initialise();
	window.MainWindowLoop();

	return 0;
}