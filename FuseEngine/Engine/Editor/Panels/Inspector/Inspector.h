#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"

namespace Fuse
{
	class Inspector : public Fuse::Panel
	{
		public:
			Inspector();
			~Inspector();

		public:
			void OnImGuiRender() override;
	};
}