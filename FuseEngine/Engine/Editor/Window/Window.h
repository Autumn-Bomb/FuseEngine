#pragma once

#include "glad.h"
#include "glfw3.h"
#include "../../../ImGui/imgui_impl_opengl3.h"
#include "../../../ImGui/imgui_impl_glfw.h"

#include "../EditorWindow/Editor.h"

#include <string>
#include <iostream>

namespace FuseEngine
{
	class Window
	{
		public:
			Window();
			~Window();

		public:
			void SetupWindow();
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
			void SetEditor(FuseEngine::Editor& editor) { m_Editor = &editor; }

		private:
			uint32_t m_WindowWidth = 1920;
			uint32_t m_WindowHeight = 1080;
			const char* m_WindowTitle = "Fuse Engine";
			const char* m_GLSLVersion = "#version 460";

		private:
			FuseEngine::Editor* m_Editor;
			GLFWwindow* m_Window;
	};
}