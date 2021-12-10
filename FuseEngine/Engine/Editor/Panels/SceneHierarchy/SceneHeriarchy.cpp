#include "SceneHierarchy.h"

Fuse::SceneHierarchy::SceneHierarchy() {}
Fuse::SceneHierarchy::~SceneHierarchy() {}

void Fuse::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());
	
	ImGui::End();
}