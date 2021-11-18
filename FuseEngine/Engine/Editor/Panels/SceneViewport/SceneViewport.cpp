#include "SceneViewport.h"

FuseEngine::SceneViewport::SceneViewport() {}
FuseEngine::SceneViewport::~SceneViewport() {}

void FuseEngine::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();
	ImGui::Image((void*)m_Scene.GetRenderTexture(), ImVec2(vWindowSize.x, vWindowSize.y));

	ImGui::End();
}