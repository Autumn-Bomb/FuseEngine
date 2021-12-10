#pragma once
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

#include "../../ResourceManager/ResourceManager.h"
#include "../../Graphics/ShaderProgram/ShaderProgram.h"
#include "../Framebuffer/Framebuffer.h" 
#include "../../EditorCamera/EditorCamera.h"
#include "../Sprite/Sprite.h"

namespace Fuse
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
			Fuse::Framebuffer& GetFramebuffer() { return m_FrameBuffer; }

			Fuse::EditorCamera& GetCamera() { return m_Camera; }

		private:
			Fuse::Framebuffer m_FrameBuffer;
			Fuse::ShaderProgram m_ShaderProgram;
			Fuse::EditorCamera m_Camera;

			uint32_t m_Player;
			Fuse::Sprite m_PlayerSprite;
	};
}