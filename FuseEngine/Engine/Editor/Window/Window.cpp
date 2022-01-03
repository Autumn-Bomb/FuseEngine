#include "Window.h"

Fuse::Window::Window() 
{ 
	m_Window = nullptr; 
	m_Editor = nullptr;
}
Fuse::Window::~Window() {}

void Fuse::Window::Initialise()
{
	InitialiseOpenGL();
	InitialiseWindow();
	InitialiseGLAD();  
	InitialiseImGui();
	InitialiseLayers();
}

void Fuse::Window::InitialiseOpenGL()
{
	// Initialise GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Fuse::Window::InitialiseGLAD()
{
	// Using GLAD, load all the OpenGL Function Pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		// If they failed to load, tell the developer
		std::cout << "Failed to initialise GLAD" << std::endl;
	}

	// Initialise an OpenGL viewport starting at 0, 0 with the windows width and height
	glViewport(0, 0, m_WindowWidth, m_WindowHeight);
}

void Fuse::Window::InitialiseImGui()
{
	// Initalise ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init(m_GLSLVersion);
	ImGui::StyleColorsDark();

	// Enable docking for ImGui Windows
	io.ConfigFlags = ImGuiConfigFlags_DockingEnable;
}

void Fuse::Window::InitialiseWindow()
{
	// Create a new GLFW Window with the specified width, height and title
	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, m_WindowTitle, NULL, NULL);

	// If the window failed to initialise
	if (m_Window == NULL)
	{
		// Tell the developer the window creation has failed and terminate GLFW
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
}

void Fuse::Window::InitialiseLayers()
{
	m_InputLayer.InitialiseCallback(m_Window);
	m_InputLayer.OnCreate();

	m_Layers.emplace_back(m_InputLayer);
}

void Fuse::Window::MainWindowLoop()
{
	while (!glfwWindowShouldClose(m_Window))
	{
		m_Editor->CalculateFPSFrametime();

		// Input
		ProcessInput();
		m_InputLayer.OnUpdate();

		// Rendering
		Render();

		// Check events and Swap Buffers
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	
	// Destroy Layers
	m_InputLayer.OnDestroy();

	// Shutdown ImGui and destroy the GLFW window, then terminate GLFW altogether
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Fuse::Window::Render()
{
	// Create a new frame for ImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Render the Editor
	m_Editor->RenderEditor();

	// Render ImGui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Fuse::Window::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}

	m_Editor->ProcessInput(m_Window);
}

void Fuse::Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}