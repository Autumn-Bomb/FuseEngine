#pragma once
#include "../BasePanel/BasePanel.h"

#include "../../../Panels/Stats/Stats.h"
#include "../../../Panels/SceneViewport/SceneViewport.h"

#include <unordered_map>

namespace FuseEngine
{
	class PanelManager
	{
		public:
			PanelManager();
			~PanelManager();

		public:
			void RenderActivePanels();

		public:
			void AddPanel(const char* name, FuseEngine::BasePanel* panel);

		public:
			FuseEngine::BasePanel* GetPanel(const char* name)
			{
				auto pairFound = m_Panels.find(name);

				if (pairFound != m_Panels.end())
					return pairFound->second;
				else
					return nullptr;
			}

		private:
			std::unordered_map<std::string, FuseEngine::BasePanel*> m_Panels;
	};
}