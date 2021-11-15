#pragma once
#include "../../Framework/Panels/BasePanel/BasePanel.h"

namespace FuseEngine
{
	class SceneViewport : public FuseEngine::BasePanel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void OnImGuiRender() override;

		private:

	};
}