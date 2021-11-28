#pragma once
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "glad.h"

#include "../../../ImGui/imgui.h"

#include <iostream>

namespace FuseEngine
{
	class Scene
	{
		public:
			Scene();
			~Scene();

		public:
			void SetupShaders();
			void BindShaders();
			void SetupFBO();

			void ProcessInput();
			void Update();
			void Render();

			uint32_t GetRenderTexture() { return m_Texture; }

		private:
			uint32_t m_VBO;
			uint32_t m_VAO;
			uint32_t m_FBO;

			uint32_t m_Texture;

		private:
			FuseEngine::ShaderProgram m_ShaderProgram;

			float m_Vertices[9] =
			{
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.0f, 0.5f, 0.0f
			};

			float translation[2] = { 0.0f, 0.0f };
	};
}