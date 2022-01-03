#pragma once
#include "../../Include/STB/stb_image.h"
#include "../Graphics/ShaderProgram/ShaderProgram.h"

namespace Fuse
{
	class ResourceManager
	{
		public:
			ResourceManager();
			~ResourceManager();

		public:
			static uint32_t LoadTexture(const char* path);
			static void LoadShader(const char* shaderName, GLuint shaderType, const char* shaderPath);

		public:
			static int GetTextureCount() { return m_TextureCount; }
			static size_t GetShaderCount() { return m_ShaderProgram.GetShadersLoaded(); }

		public:
			Fuse::ShaderProgram& GetShaderProgram() { return m_ShaderProgram; }

		public:
			static Fuse::ShaderProgram m_ShaderProgram;
			static int m_TextureCount;
	};
}