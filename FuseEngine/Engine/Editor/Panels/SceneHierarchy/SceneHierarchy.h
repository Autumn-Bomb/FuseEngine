#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"

namespace Fuse
{
	class SceneHierarchy : public Fuse::Panel
	{
		public:
			SceneHierarchy();
			~SceneHierarchy();

		public:
			void OnImGuiRender() override;
	};
}