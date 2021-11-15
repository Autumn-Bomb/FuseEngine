#pragma once
#include "glad.h"
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
			void Render();

			uint32_t GetRenderTexture() { return m_Texture; }

		private:
			uint32_t m_VBO;
			uint32_t m_VAO;
			uint32_t m_FBO;
			uint32_t m_RBO;

			uint32_t m_Texture;

			uint32_t m_VertexShader;
			uint32_t m_FragmentShader;
			uint32_t m_ShaderProgram;

		private:
			const char* m_VertexShaderSource = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main()\n"
				"{\n"
				"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";

			const char* m_FragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColour;\n"
				"in vec2 TexCoords;\n"
				"uniform sampler2D ScreenTexture;\n"
				"void main()\n"
				"{\n"
				"  FragColour = texture(ScreenTexture, TexCoords);\n"
				"}\0";

			float m_Vertices[9] =
			{
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.0f, 0.5f, 0.0f
			};
	};
}