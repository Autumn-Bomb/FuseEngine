#pragma once
#include "../../../Framework/Panels/BasePanel/BasePanel.h"
#include "../../../Framework/Scene/Scene.h"

namespace Fuse
{
	class SceneViewport : public Fuse::BasePanel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void OnImGuiRender() override;

		public:
			void SetActiveScene(Fuse::Scene& scene) { m_Scene = scene; }

		private:
			Fuse::Scene m_Scene;
	};
}