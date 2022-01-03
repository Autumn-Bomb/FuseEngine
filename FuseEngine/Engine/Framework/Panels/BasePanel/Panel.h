#pragma once
#include "../../../ImGui/imgui.h"
#include <glad.h>

namespace Fuse
{
	class Panel
	{
		public:
			Panel() { m_IsActive = true; }
			~Panel() {}

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