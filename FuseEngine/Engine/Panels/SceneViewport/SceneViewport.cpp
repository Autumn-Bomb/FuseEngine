#include "SceneViewport.h"

FuseEngine::SceneViewport::SceneViewport() {}
FuseEngine::SceneViewport::~SceneViewport() {}

void FuseEngine::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse);

	// Render ImGui Texture here with FBO

	ImGui::End();
}