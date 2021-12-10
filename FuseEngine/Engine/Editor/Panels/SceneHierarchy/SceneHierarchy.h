#pragma once
#include "../../../Framework/Panels/BasePanel/BasePanel.h"

namespace Fuse
{
	class SceneHierarchy : public Fuse::BasePanel
	{
		public:
			SceneHierarchy();
			~SceneHierarchy();

		public:
			void OnImGuiRender() override;
	};
}