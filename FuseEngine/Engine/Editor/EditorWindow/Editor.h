#pragma once

#include "../../Framework/Panels/PanelManager/PanelManager.h"
#include "../Panels/MenuBar/Menubar.h"
#include "../../Framework/TestScene/TestScene.h"
#include "../../Framework/Layers/InputLayer/InputLayer.h"

#include <glfw3.h>

namespace Fuse
{
	class Editor
	{
		public:
			Editor();
			~Editor();

		public:
			void RenderEditor();

			void RenderActivePanels();
			void HandlePanelDocking();

			void SetupScene();
			void SetInputLayer(Fuse::InputLayer& inputLayer) { m_InputLayer = inputLayer; }

		public:
			void ProcessInput(GLFWwindow* window);
			void CalculateFPSFrametime();
			void ResetLastTime() { m_FPS = 0; m_LastTime = glfwGetTime(); }

		private:
			ImGuiID m_DockSpaceID = 0;

		private:
			Fuse::Menubar m_MenuBar;

			Fuse::Profiler m_Profiler;
			Fuse::SceneViewport m_SceneView;
			Fuse::GameViewport m_GameView;
			Fuse::SceneHierarchy m_SceneHierarchy;
			Fuse::Resources m_Resources;
			Fuse::Inspector m_Inspector;
			Fuse::Console m_Console;
			Fuse::AssetBrowser m_AssetBrowser;

		private:
			Fuse::PanelManager m_PanelManager;
			Fuse::TestScene m_Scene;
			Fuse::InputLayer m_InputLayer;

		private:
			double m_CurrentTime;
			double m_LastTime;
			double m_FrameTime;
			int m_FPS;
	};
}