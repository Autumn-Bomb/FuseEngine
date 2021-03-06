#pragma once
#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"

#include "../../../ResourceManager/ResourceManager.h"
#include "../../../Graphics/ShaderProgram/ShaderProgram.h"
#include "../../Framebuffer/Framebuffer.h" 
#include "../../../EditorCamera/EditorCamera.h"

namespace Fuse
{
	class Renderer2D
	{
		public:
			Renderer2D();
			~Renderer2D();

		public:
			static void InitialiseRenderer(Fuse::EditorCamera& camera);

		public:
			static void Bind();
			static void DrawSprite(uint32_t texture, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour);
			static void DrawSpriteBatched(uint32_t originTexture, int x, int y, int width, int height, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour);
			static void Unbind();

		public:
			static uint32_t GetFramebufferObject() { return m_FrameBuffer.GetFramebufferObject(); }
			static Fuse::Framebuffer& GetFramebuffer() { return m_FrameBuffer; }	

			void DeleteFramebuffer() { m_FrameBuffer.DeleteCurrentBuffer(); }

		public:
			inline static int m_DrawCalls;
			inline static int GetDrawcalls() { return m_DrawCalls; }

		private:
			static void InitialiseBuffers();

		private:
			struct m_QuadBase
			{
				inline static float m_Vertices[32] =
				{
					// positions          // colors           // texture coords
					 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
					 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
					-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
					-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
				};

				inline static uint32_t indices[6] =
				{
					0, 1, 3,
					1, 2, 3
				};

				inline static uint32_t m_QuadVAO;
				inline static uint32_t m_QuadVBO;
				inline static uint32_t m_QuadEBO;

				inline static uint32_t m_QuadTexture;
			};

			inline static glm::mat4 m_Transform;

		private:
			inline static m_QuadBase m_Quad;
			inline static Fuse::Framebuffer m_FrameBuffer;
			inline static Fuse::EditorCamera m_EditorCamera;
	};
}