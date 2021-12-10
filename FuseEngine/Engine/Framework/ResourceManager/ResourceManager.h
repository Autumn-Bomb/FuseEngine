#pragma once
#include "../../Include/STB/stb_image.h"
#include "../Graphics/ShaderProgram/ShaderProgram.h"

#include <unordered_map>

namespace Fuse
{
	class ResourceManager
	{
		public:
			ResourceManager();
			~ResourceManager();

		public:
			static uint32_t LoadTexture(const char* path);

		public:
			static int GetTextureCount() { return m_TextureCount; }
			static int GetShaderCount() { return m_ShaderCount; }

		public:
			static int m_TextureCount;
			static int m_ShaderCount;
	};
}