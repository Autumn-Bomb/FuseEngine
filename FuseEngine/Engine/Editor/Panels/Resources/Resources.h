#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"
#include "../../../Framework/ResourceManager/ResourceManager.h"

namespace Fuse
{
	class Resources : public Fuse::Panel
	{
		public:
			Resources();
			~Resources();

		public:
			void OnImGuiRender() override;
			void AddAllResources();

		private:
			size_t m_TextureCount;
			size_t m_ShaderCount;
	};
}