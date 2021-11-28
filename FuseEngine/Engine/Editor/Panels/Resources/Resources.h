#pragma once
#include "../../../Framework/Panels/BasePanel/BasePanel.h"
#include "../../../Framework/ResourceManager/ResourceManager.h"

namespace FuseEngine
{
	class Resources : public FuseEngine::BasePanel
	{
		public:
			Resources();
			~Resources();

		public:
			void OnImGuiRender() override;
			void AddAllResources();

		private:
			FuseEngine::ResourceManager m_ResourceManager;
	};
}