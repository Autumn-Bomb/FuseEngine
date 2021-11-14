#pragma once

#include "glad.h"
#include "glfw3.h"
#include "../../ImGui/imgui_impl_opengl3.h"
#include "../../ImGui/imgui_impl_glfw.h"

#include "../Editor/Editor.h"

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
			void InitialiseOpenGL();
			void InitialiseGLAD();
			void CreateWindow();
			void MainWindowLoop();
			void ProcessInput();

			void PrintGPUSpecs();

			void Render();

		public:	
			void StatsWindow();

		public:
			void InitialiseImGui();

		public:
			static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

		public:
			void SetEditor(FuseEngine::Editor& editor) { m_Editor = &editor; }

		private:
			unsigned int m_WindowWidth = 1920;
			unsigned int m_WindowHeight = 1080;
			const char* m_WindowTitle = "Fuse Engine";
			const char* m_GLSLVersion = "#version 460";

		private:
			const GLubyte* m_Vendor;
			const GLubyte* m_Renderer;
			const GLubyte* m_OpenGlVersion;

		private:
			FuseEngine::Editor* m_Editor;
			GLFWwindow* m_Window;
	};
}