#include "Inspector.h"

Fuse::Inspector::Inspector(){}
Fuse::Inspector::~Inspector() {}

void Fuse::Inspector::OnImGuiRender()
{
	ImGui::Begin("Inspector", &GetActiveState());

	ImGui::End();
}