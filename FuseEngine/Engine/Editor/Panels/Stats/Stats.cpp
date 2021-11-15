#include "Stats.h"

FuseEngine::Stats::Stats()
{
	m_Vendor = nullptr;
	m_Renderer = nullptr;
	m_OpenGlVersion = nullptr;
}
FuseEngine::Stats::~Stats() {}

void FuseEngine::Stats::OnImGuiRender()
{
	ImGui::Begin("Stats", &GetActiveState(), ImGuiWindowFlags_NoCollapse);

	PrintStatsToConsole();

	ImGui::Text("Vendor: %s", (char*)m_Vendor);
	ImGui::Text("Renderer: %s", (char*)m_Renderer);
	ImGui::Text("OpenGL Version: %s", (char*)m_OpenGlVersion);

	ImGui::End();
}

void FuseEngine::Stats::PrintStatsToConsole()
{
	if (!statsPrinted)
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

		statsPrinted = true;
	}
}