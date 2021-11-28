#pragma once
#include <unordered_map>
#include "../Graphics/ShaderProgram/ShaderProgram.h"

namespace FuseEngine
{
	class ResourceManager
	{
		public:
			ResourceManager();
			~ResourceManager();

		private:

		private:
			int m_TextureCount;
			int m_ShaderCount;
			int m_SoundCount;
	};
}