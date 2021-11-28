#include "GameViewport.h"

FuseEngine::GameViewport::GameViewport() {}
FuseEngine::GameViewport::~GameViewport() {}

void FuseEngine::GameViewport::OnImGuiRender()
{
	ImGui::Begin("Game View", &GetActiveState(), ImGuiWindowFlags_NoCollapse);

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();
	ImGui::Image((ImTextureID)m_Scene.GetRenderTexture(), ImVec2(vWindowSize.x, vWindowSize.y));

	ImGui::End();
}