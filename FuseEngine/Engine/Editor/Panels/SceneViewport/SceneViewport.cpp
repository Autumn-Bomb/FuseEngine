#include "SceneViewport.h"

Fuse::SceneViewport::SceneViewport() {}
Fuse::SceneViewport::~SceneViewport() {}

void Fuse::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();

	m_Scene.GetRenderer().GetFramebuffer().Resize(vWindowSize.x, vWindowSize.y);
	ImGui::Image((uint32_t*)m_Scene.GetRenderer().GetFramebufferObject(), ImVec2(vWindowSize.x, vWindowSize.y));
	//m_Scene.GetRenderer().GetCamera().ResizeCamera(vWindowSize.x, vWindowSize.y);

	ImGui::End();
}