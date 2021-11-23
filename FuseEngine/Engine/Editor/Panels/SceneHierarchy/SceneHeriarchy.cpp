#include "SceneHierarchy.h"

FuseEngine::SceneHierarchy::SceneHierarchy() {}
FuseEngine::SceneHierarchy::~SceneHierarchy() {}

void FuseEngine::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());

	ImGui::Button("Create Entity", ImVec2(ImGui::GetWindowSize().x, 20));
	
	ImGui::End();
}