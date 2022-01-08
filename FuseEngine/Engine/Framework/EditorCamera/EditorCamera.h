#pragma once

#include "../GLM/glm.hpp"
#include "../GLM/gtc/matrix_transform.hpp"
#include "../Layers/InputLayer/InputLayer.h"

namespace Fuse
{
	class EditorCamera
	{
		public:
			EditorCamera() {}
			EditorCamera(float left, float right, float bottom, float top)
			{
				m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
				m_ViewMatrix = glm::mat4(1.0f);
				m_Transform = glm::mat4(1.0f);

				m_Rotation = 0.0f;
				m_MovementSpeed = 0.01f;
				m_Position = glm::vec3(0.0f, 0.0f, 0.0f);

				m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
			}
			~EditorCamera() {}

		public:
			const glm::vec3& GetPosition() const { return m_Position; }
			void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }

			float GetRotation() const { return m_Rotation; }
			void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		public:
			void HandleInput(Fuse::InputLayer& inputLayer)
			{
				if (inputLayer.IsKeyDown('W'))
				{
					SetPosition(glm::vec3(GetPosition().x, GetPosition().y - 0.1f * m_MovementSpeed, 0.0f));
					std::cout << "Moving up" << std::endl;
				} 
				else if (inputLayer.IsKeyDown('S'))
				{
					SetPosition(glm::vec3(GetPosition().x, GetPosition().y + 0.1f * m_MovementSpeed, 0.0f));
					std::cout << "Moving down" << std::endl;
				}
				else if (inputLayer.IsKeyDown('A'))
				{
					SetPosition(glm::vec3(GetPosition().x - 0.1f * m_MovementSpeed, GetPosition().y, 0.0f));
					std::cout << "Moving down" << std::endl;
				}
				else if (inputLayer.IsKeyDown('D'))
				{
					SetPosition(glm::vec3(GetPosition().x + 0.1f * m_MovementSpeed, GetPosition().y, 0.0f));
					std::cout << "Moving down" << std::endl;
				}
			}

		public:
			const glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
			const glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
			const glm::mat4 GetProjectionViewMatrix() const { return m_ProjectionViewMatrix; }

		private:
			void RecalculateViewMatrix()
			{
				m_Transform = glm::translate(glm::mat4(1.0f), m_Position) *
				 glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

				m_ViewMatrix = glm::inverse(m_Transform);
				m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
			}

		private:
			glm::mat4 m_Transform;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ProjectionViewMatrix;

		private:
			float m_MovementSpeed; 
			glm::vec3 m_Position;
			float m_Rotation;
	};
}