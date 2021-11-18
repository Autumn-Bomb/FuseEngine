#include "Menubar.h"

FuseEngine::Menubar::Menubar() {}
FuseEngine::Menubar::~Menubar() {}

void FuseEngine::Menubar::OnImGuiRender()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Open");
			ImGui::MenuItem("Save");
			ImGui::MenuItem("Shutdown");

			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Window"))
		{
			ImGui::MenuItem("Scene Viewport");
			ImGui::MenuItem("Game Viewport");
			ImGui::MenuItem("Stats");

			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}
}