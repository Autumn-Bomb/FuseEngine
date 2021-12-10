#include "ResourceManager.h"

int Fuse::ResourceManager::m_TextureCount = 0;
int Fuse::ResourceManager::m_ShaderCount = 0;

Fuse::ResourceManager::ResourceManager() {}
Fuse::ResourceManager::~ResourceManager() {}

uint32_t Fuse::ResourceManager::LoadTexture(const char* path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width = 0;
	int height = 0;
	int nrChannels = 0;

	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

	if (data)
	{
		GLenum textureFormat = 0;
		switch (nrChannels)
		{
			case 1:
			{
				textureFormat = GL_RED;
			}
				break;
			case 3:
			{
				textureFormat = GL_RGB;
			}
				break;
			case 4:
			{
				textureFormat = GL_RGBA;
			}
				break;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, width, height, 0, textureFormat, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
		++m_TextureCount;
	}
	else
	{
		std::cout << "Couldn't locate file!" << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}