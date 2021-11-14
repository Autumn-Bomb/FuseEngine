#include "Window.h"

FuseEngine::Window::Window() 
{ 
	m_Window = nullptr; 
	m_Editor = nullptr;

	m_Vendor = nullptr;
	m_Renderer = nullptr;
	m_OpenGlVersion = nullptr;
}
FuseEngine::Window::~Window() { /*delete m_Window;*/ }

void FuseEngine::Window::InitialiseOpenGL()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void FuseEngine::Window::InitialiseGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
	}

	glViewport(0, 0, m_WindowWidth, m_WindowHeight);
}

void FuseEngine::Window::InitialiseImGui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init(m_GLSLVersion);
	ImGui::StyleColorsDark();

	io.ConfigFlags = ImGuiConfigFlags_DockingEnable;
}

void FuseEngine::Window::CreateWindow()
{
	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, m_WindowTitle, NULL, NULL);

	if (m_Window == NULL)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_Window);
}

void FuseEngine::Window::MainWindowLoop()
{
	while (!glfwWindowShouldClose(m_Window))
	{
		// Input
		ProcessInput();

		// Rendering
		Render();

		// Check events and Swap Buffers
		glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void FuseEngine::Window::Render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	m_Editor->RenderEditor();
	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void FuseEngine::Window::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
}

void FuseEngine::Window::PrintGPUSpecs()
{
	m_Vendor = new GLubyte();
	m_Renderer = new GLubyte();
	m_OpenGlVersion = new GLubyte();

	m_Vendor = glGetString(GL_VENDOR);
	m_Renderer = glGetString(GL_RENDERER);
	m_OpenGlVersion = glGetString(GL_VERSION);

	std::cout << "GPU Vendor: " << m_Vendor << std::endl;
	std::cout << "OpenGL Renderer: " << m_Renderer << std::endl;
	std::cout << "OpenGL Version: " << m_OpenGlVersion << std::endl;
}

void FuseEngine::Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void FuseEngine::Window::StatsWindow()
{
	ImGui::Begin("Stats");

	ImGui::Text("Vendor: %s", (char*)m_Vendor);
	ImGui::Text("Renderer: %s", (char*)m_Renderer);
	ImGui::Text("OpenGL Version: %s", (char*)m_OpenGlVersion);

	ImGui::End();
}