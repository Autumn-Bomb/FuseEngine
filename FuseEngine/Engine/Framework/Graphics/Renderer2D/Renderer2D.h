#pragma once
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

#include "../../ResourceManager/ResourceManager.h"
#include "../../Graphics/ShaderProgram/ShaderProgram.h"
#include "../Framebuffer/Framebuffer.h" 
#include "../../Camera/Camera.h"

#include "../Sprite/Sprite.h"

namespace FuseEngine
{
	class Renderer2D
	{
		public:
			Renderer2D();
			~Renderer2D();

		public:
			void InitialiseRenderer();

		public:
			void Render();

		public:
			uint32_t GetFramebufferObject() { return m_FrameBuffer.GetFramebufferObject(); }
			FuseEngine::Framebuffer& GetFramebuffer() { return m_FrameBuffer; }

		private:
			FuseEngine::Framebuffer m_FrameBuffer;
			FuseEngine::ShaderProgram m_ShaderProgram;
			FuseEngine::Camera m_Camera;

			uint32_t m_Background;
			uint32_t m_Middleground;
			FuseEngine::Sprite m_BackgroundSprite;
			FuseEngine::Sprite m_MiddlegroundSprite;
	};
}