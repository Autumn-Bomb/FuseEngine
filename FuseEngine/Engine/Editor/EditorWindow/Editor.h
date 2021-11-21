#pragma once

#include "../../Framework/Panels/PanelManager/PanelManager.h"
#include "../Panels/MenuBar/Menubar.h"
#include "../../Framework/Scene/Scene.h"

#include <glfw3.h>

namespace FuseEngine
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

		public:
			void ProcessInput(GLFWwindow* window);
			void CalculateFPSFrametime();
			void ResetLastTime() { m_FPS = 0; m_LastTime = glfwGetTime(); }

		private:
			ImGuiID m_DockSpaceID = 0;

		private:
			FuseEngine::Menubar m_MenuBar;

			FuseEngine::Profiler m_Profiler;
			FuseEngine::SceneViewport m_SceneView;
			FuseEngine::GameViewport m_GameView;
			FuseEngine::SceneHierarchy m_SceneHierarchy;

		private:
			FuseEngine::Scene m_Scene;
			FuseEngine::PanelManager m_PanelManager;

		private:
			double m_LastTime;
			double m_FrameTime;
			int m_FPS;
	};
}