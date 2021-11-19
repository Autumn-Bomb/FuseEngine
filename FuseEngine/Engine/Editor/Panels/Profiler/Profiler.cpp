#include "Profiler.h"

FuseEngine::Profiler::Profiler()
{
	m_Vendor = nullptr;
	m_Renderer = nullptr;
	m_OpenGlVersion = nullptr;

	m_FPS = 0;
	m_Frametime = 0;
}
FuseEngine::Profiler::~Profiler() {}

void FuseEngine::Profiler::OnImGuiRender()
{
	ImGui::Begin("Profiler", &GetActiveState(), ImGuiWindowFlags_NoCollapse);

	if (!statsPrinted)
	{
		PrintStatsToConsole();
	}

	if (ImGui::CollapsingHeader("RENDERING STATS"))
	{
		ImGui::TextWrapped("Vendor: %s", (char*)m_Vendor);
		ImGui::TextWrapped("Renderer: %s", (char*)m_Renderer);
		ImGui::TextWrapped("OpenGL Version: %s", (char*)m_OpenGlVersion);
	}
	if (ImGui::CollapsingHeader("ENGINE STATS"))
	{
		ImGui::TextWrapped("FPS: %i", m_FPS);
		ImGui::TextWrapped("Frametime: %i", m_Frametime);
	}
	if (ImGui::CollapsingHeader("GPU STATS"))
	{
		ImGui::Text("Entities: %i", 0);
		ImGui::Text("Draw Calls: %i", 0);
		ImGui::Text("Vertices: %i", 0);
		ImGui::Text("Indices: %i", 0);
	}
	
	ImGui::End();
}

void FuseEngine::Profiler::PrintStatsToConsole()
{
	m_Vendor = new GLubyte();
	m_Renderer = new GLubyte();
	m_OpenGlVersion = new GLubyte();

	m_Vendor = glGetString(GL_VENDOR);
	m_Renderer = glGetString(GL_RENDERER);
	m_OpenGlVersion = glGetString(GL_VERSION);

	statsPrinted = true;
}