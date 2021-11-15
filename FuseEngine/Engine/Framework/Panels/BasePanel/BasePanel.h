#pragma once
#include "../../../ImGui/imgui.h"
#include <glad.h>

namespace FuseEngine
{
	class BasePanel
	{
		public:
			BasePanel() { m_IsActive = true; }
			~BasePanel() {}

		public:
			virtual void OnImGuiRender() {}

		public:
			void ShowPanel(bool show) { m_IsActive = show; }
			void HidePanel() { m_IsActive = false; }

		public:
			bool& GetActiveState() { return m_IsActive; }

		private:
			bool m_IsActive;
	};
}