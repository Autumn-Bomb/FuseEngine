#include "Window/Window.h"

int main()
{
	FuseEngine::Window window;
	FuseEngine::Editor editor;

	window.SetEditor(editor);

	window.InitialiseOpenGL();
	window.CreateWindow();
	window.InitialiseGLAD();
	window.InitialiseImGui();
	window.PrintGPUSpecs();

	window.MainWindowLoop();

	glfwTerminate();
	return 0;
}