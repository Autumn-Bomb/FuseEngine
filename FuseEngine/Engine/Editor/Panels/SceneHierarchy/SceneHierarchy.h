#pragma once
#include "../../../Framework/Panels/BasePanel/BasePanel.h"

namespace FuseEngine
{
	class SceneHierarchy : public FuseEngine::BasePanel
	{
		public:
			SceneHierarchy();
			~SceneHierarchy();

		public:
			void OnImGuiRender() override;
	};
}