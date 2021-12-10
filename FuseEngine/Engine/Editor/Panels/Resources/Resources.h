#pragma once
#include "../../../Framework/Panels/BasePanel/BasePanel.h"
#include "../../../Framework/ResourceManager/ResourceManager.h"

namespace Fuse
{
	class Resources : public Fuse::BasePanel
	{
		public:
			Resources();
			~Resources();

		public:
			void OnImGuiRender() override;
			void AddAllResources();

		private:
			int m_TextureCount;
			int m_ShaderCount;
	};
}