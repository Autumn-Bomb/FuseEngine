#pragma once

#include "glad.h"
#include "glfw3.h"
#include "../../../ImGui/imgui_impl_opengl3.h"
#include "../../../ImGui/imgui_impl_glfw.h"

#include "../EditorWindow/Editor.h"
#include "../../Framework/Input/Input.h"

#include <string>
#include <iostream>

namespace Fuse
{
	class Window
	{
		public:
			Window();
			Window(Fuse::Editor& editor)
			{
				m_Editor = &editor;
			}
			~Window();

		public:
			void Initialise();
			void InitialiseOpenGL();
			void InitialiseGLAD();
			void CreateWindow();
			void MainWindowLoop();
			void ProcessInput();

		public:
			void Render();

		public:
			void InitialiseImGui();

		public:
			static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

		public:
			void SetEditor(Fuse::Editor& editor) { m_Editor = &editor; }

		private:
			uint32_t m_WindowWidth = 1920;
			uint32_t m_WindowHeight = 1080;
			const char* m_WindowTitle = "Fuse Engine";
			const char* m_GLSLVersion = "#version 460";

		private:
			Fuse::Editor* m_Editor;
			GLFWwindow* m_Window;
	};
}