#pragma once
#include "../../../ImGui/imgui.h"
#include "../../../Framework/Panels/BasePanel/BasePanel.h"
#include "../../../Framework/Scene/Scene.h"

namespace Fuse
{
	class GameViewport : public Fuse::BasePanel
	{
		public:
			GameViewport();
			~GameViewport();

		public:
			void OnImGuiRender() override;

		public:
			void SetActiveScene(Fuse::Scene& scene) { m_Scene = scene; }

		private:
			Fuse::Scene m_Scene;
	};
}