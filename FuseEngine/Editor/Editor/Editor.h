#pragma once
#include "../../ImGui/imgui.h"

namespace FuseEngine
{
	class Editor
	{
		public:
			Editor();
			~Editor();

		public:
			void RenderEditor();
			void HandlePanelDocking();

		private:
			ImGuiID m_DockSpaceID = 0;
	};
}