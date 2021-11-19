#include "Editor.h"

FuseEngine::Editor::Editor()
{
	m_PanelManager.AddPanel("Stats", &m_Profiler);
	m_PanelManager.AddPanel("Scene View", &m_SceneView);
	m_PanelManager.AddPanel("Game View", &m_GameView);
	m_PanelManager.AddPanel("Scene Hierarchy", &m_SceneHierarchy);
}
FuseEngine::Editor::~Editor() {}

void FuseEngine::Editor::ProcessInput(GLFWwindow* window)
{
	// Handle any key input
}

void FuseEngine::Editor::SetupScene()
{
	m_Scene.SetupShaders();
	m_Scene.BindShaders();
	m_Scene.SetupFBO();

	m_SceneView.SetActiveScene(m_Scene);
	m_GameView.SetActiveScene(m_Scene);
}

void FuseEngine::Editor::RenderEditor()
{
	ImGui::Begin("Editor", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar);
	
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

	ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
	ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;
	ImGui::GetStyle().WindowMenuButtonPosition = ImGuiDir_None;

	ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);

	ImGui::PopStyleVar();

	m_MenuBar.OnImGuiRender();
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