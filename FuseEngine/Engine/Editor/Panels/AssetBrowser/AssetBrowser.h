#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"

namespace Fuse
{
	class AssetBrowser : public Fuse::Panel
	{
		public:
			AssetBrowser();
			~AssetBrowser();

		public:
			void OnImGuiRender() override;
	};
}