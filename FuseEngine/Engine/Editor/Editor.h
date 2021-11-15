#pragma once
#include "../../ImGui/imgui.h"
#include "../Framework/Panels/PanelManager/PanelManager.h"
#include <glfw3.h>

namespace FuseEngine
{
	class Editor
	{
		public:
			Editor();
			~Editor();

		public:
			void RenderEditor();
			void RenderActivePanels();
			void HandlePanelDocking();

		public:
			void ProcessInput(GLFWwindow* window);

		private:
			ImGuiID m_DockSpaceID = 0;

		private:
			FuseEngine::PanelManager m_PanelManager;
	};
}