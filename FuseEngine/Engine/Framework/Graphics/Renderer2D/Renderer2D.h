#pragma once
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

#include "../../ResourceManager/ResourceManager.h"
#include "../../Graphics/ShaderProgram/ShaderProgram.h"
#include "../Framebuffer/Framebuffer.h" 
#include "../Sprite/Sprite.h"

#include <glfw3.h>

namespace Fuse
{
	class Renderer2D
	{
		public:
			Renderer2D();
			~Renderer2D();

		public:
			void InitialiseRenderer(Fuse::ShaderProgram& shaderProgram);

		public:
			void Bind();
			void DrawSprite(Fuse::Sprite& sprite, uint32_t texture, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour);
			void DrawSpriteBatched(Fuse::Sprite& sprite, uint32_t originTexture, int x, int y, int width, int height, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour);
			void Unbind();

		public:
			uint32_t GetFramebufferObject() { return m_FrameBuffer.GetFramebufferObject(); }
			Fuse::Framebuffer& GetFramebuffer() { return m_FrameBuffer; }			 

		public:
			static int m_DrawCalls;
			static int GetDrawcalls() { return m_DrawCalls; }

		private:
			Fuse::Framebuffer m_FrameBuffer;
			Fuse::ShaderProgram m_ShaderProgram;
	};
}