#pragma once
#include "../../../ImGui/imgui.h"
#include "../../../Framework/Panels/BasePanel/BasePanel.h"
#include "../../../Framework/Scene/Scene.h"

namespace FuseEngine
{
	class GameViewport : public FuseEngine::BasePanel
	{
		public:
			GameViewport();
			~GameViewport();

		public:
			void OnImGuiRender() override;

		public:
			void SetActiveScene(FuseEngine::Scene& scene) { m_Scene = scene; }

		private:
			FuseEngine::Scene m_Scene;
	};
}