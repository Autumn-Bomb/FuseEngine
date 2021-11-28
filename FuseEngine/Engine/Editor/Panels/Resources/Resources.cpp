#include "Resources.h"

FuseEngine::Resources::Resources() {}
FuseEngine::Resources::~Resources() {}

void FuseEngine::Resources::AddAllResources()
{
	// Used to loop through all resources stored in the ResourceManager and add them to the list
}

void FuseEngine::Resources::OnImGuiRender()
{
	ImGui::Begin("Resources", &GetActiveState());

	ImGui::TreeNode("Textures");
	ImGui::TreeNode("Texture Atlas");
	ImGui::TreeNode("Sounds");
	
	ImGui::TreeNode("Shaders");

	ImGui::End();
}