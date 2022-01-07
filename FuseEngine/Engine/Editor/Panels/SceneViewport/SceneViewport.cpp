#include "SceneViewport.h"

Fuse::SceneViewport::SceneViewport()
{
	m_Scene = new Fuse::TestScene();
}
Fuse::SceneViewport::~SceneViewport() {}

void Fuse::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();
	ImGui::Image((ImTextureID)m_Scene->GetRenderer().GetFramebufferObject(), vWindowSize);
	ImGui::End();
}