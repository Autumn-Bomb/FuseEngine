#include "Editor.h"

FuseEngine::Editor::Editor()
{
	m_PanelManager.CreatePanels();
}
FuseEngine::Editor::~Editor() {}

void FuseEngine::Editor::ProcessInput(GLFWwindow* window)
{
	/*if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{	
	}*/
}

void FuseEngine::Editor::SetupScene()
{
	m_Scene.SetupShaders();
	m_Scene.BindShaders();
}

void FuseEngine::Editor::RenderEditor()
{
	ImGui::Begin("Editor", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar);
	
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

	ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
	ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

	ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);

	ImGui::PopStyleVar();

	HandlePanelDocking();
	RenderActivePanels();

	ImGui::End();
}

void FuseEngine::Editor::RenderActivePanels()
{
	m_PanelManager.RenderActivePanels();
}

void FuseEngine::Editor::HandlePanelDocking()
{
	m_DockSpaceID = ImGui::GetID("MainDockSpace");
	ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);
}