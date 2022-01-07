#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"
#include "../../../Framework/TestScene/TestScene.h"

namespace Fuse
{
	class SceneViewport : public Fuse::Panel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void OnImGuiRender() override;

		public:
			void SetActiveScene(Fuse::TestScene& activeScene) { m_Scene = &activeScene; }

		private:
			Fuse::TestScene* m_Scene;
	};
}