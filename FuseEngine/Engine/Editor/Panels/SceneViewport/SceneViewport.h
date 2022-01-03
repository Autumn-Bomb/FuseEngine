#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"

namespace Fuse
{
	class SceneViewport : public Fuse::Panel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void OnImGuiRender() override;
	};
}