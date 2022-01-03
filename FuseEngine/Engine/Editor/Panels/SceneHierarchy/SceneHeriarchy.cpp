#include "SceneHierarchy.h"

Fuse::SceneHierarchy::SceneHierarchy() {}
Fuse::SceneHierarchy::~SceneHierarchy() {}

void Fuse::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());
	
	// Loop through all entities in a scene and add them to the Hierarchy, also allow the addition of new entities through a drop down menu on button click

	ImGui::End();
}