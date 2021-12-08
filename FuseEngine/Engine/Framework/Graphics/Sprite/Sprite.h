#pragma once
#include <cstdint>

#include "../GLM/glm.hpp"
#include "../../../../Includes/Include/GLM/gtx/transform.hpp"
#include "../../../../Includes/Include/GLM/gtc/type_ptr.hpp"

#include "../ShaderProgram/ShaderProgram.h"

namespace FuseEngine
{
	class Sprite
	{
		public:
			Sprite();
			Sprite(FuseEngine::ShaderProgram& shaderProgram);
			~Sprite();

		public:
			void Render(uint32_t texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec4 color);

		public:
			void SetTranslation(glm::vec2 translation) { m_Transform = glm::translate(m_Transform, glm::vec3(translation.x, translation.y, 1.0f)); };

		private:
			FuseEngine::ShaderProgram m_ShaderProgram;

			uint32_t m_QuadVAO;
			uint32_t m_QuadVBO;
			uint32_t m_QuadEBO;

			uint32_t m_QuadTexture;

		private:
			glm::mat4 m_Transform;

		private:
			float m_Vertices[32] = {
				// positions          // colors           // texture coords
				 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
				 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
				-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
				-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
			};

			uint32_t indices[6] =
			{
				0, 1, 3,
				1, 2, 3
			};
	};
}