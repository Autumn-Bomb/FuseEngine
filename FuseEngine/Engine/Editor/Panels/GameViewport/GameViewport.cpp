#include "GameViewport.h"

Fuse::GameViewport::GameViewport() {}
Fuse::GameViewport::~GameViewport() {}

void Fuse::GameViewport::OnImGuiRender()
{
	ImGui::Begin("Game View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();
	ImGui::Image((uint32_t*)m_Scene.GetRenderer().GetFramebufferObject(), ImVec2(vWindowSize.x, vWindowSize.y));

	ImGui::End();
}