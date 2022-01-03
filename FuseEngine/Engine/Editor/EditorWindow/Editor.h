#pragma once

#include "../../Framework/Panels/PanelManager/PanelManager.h"
#include "../../Framework/Scenes/SceneManager/SceneManager.h"
#include "../Panels/MenuBar/Menubar.h"

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

		private:
			Fuse::SceneManager m_SceneManager;
			Fuse::PanelManager m_PanelManager;

		private:
			double m_LastTime;
			double m_FrameTime;
			int m_FPS;
	};
}