#include "SceneHierarchy.h"

FuseEngine::SceneHierarchy::SceneHierarchy() {}
FuseEngine::SceneHierarchy::~SceneHierarchy() {}

void FuseEngine::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());
	
	ImGui::End();
}