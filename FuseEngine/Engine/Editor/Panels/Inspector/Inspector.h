#pragma once
#include "../../../Framework/Panels/BasePanel/BasePanel.h"

namespace Fuse
{
	class Inspector : public Fuse::BasePanel
	{
		public:
			Inspector();
			~Inspector();

		public:
			void OnImGuiRender() override;
	};
}