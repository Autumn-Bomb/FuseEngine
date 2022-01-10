#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"
#include "../../../Framework/SceneManager/SceneManager.h"

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