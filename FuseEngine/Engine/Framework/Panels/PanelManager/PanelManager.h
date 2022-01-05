#pragma once
#include "../BasePanel/Panel.h"

#include "../../../Editor/Panels/Profiler/Profiler.h"
#include "../../../Editor/Panels/SceneViewport/SceneViewport.h"
#include "../../../Editor/Panels/GameViewport/GameViewport.h"
#include "../../../Editor/Panels/SceneHierarchy/SceneHierarchy.h"
#include "../../../Editor/Panels/Resources/Resources.h"
#include "../../../Editor/Panels/Inspector/Inspector.h"
#include "../../../Editor/Panels/Console/Console.h"

#include <unordered_map>

namespace Fuse
{
	class PanelManager
	{
		public:
			PanelManager();
			~PanelManager();

		public:
			void RenderActivePanels();

		public:
			void AddPanel(const char* name, Fuse::Panel* panel);

		public:
			Fuse::Panel* GetPanel(const char* name)
			{
				auto pairFound = m_Panels.find(name);

				if (pairFound != m_Panels.end())
					return pairFound->second;
				else
					return nullptr;
			}

		private:
			std::unordered_map<std::string, Fuse::Panel*> m_Panels;
	};
}