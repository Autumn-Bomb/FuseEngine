#pragma once
#include "../../Framework/Panels/BasePanel/BasePanel.h"
#include "../../Framework/Scene/Scene.h"

namespace FuseEngine
{
	class SceneViewport : public FuseEngine::BasePanel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void OnImGuiRender() override;
			void RenderScene(FuseEngine::Scene scene);
	};
}