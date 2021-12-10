#pragma once
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "../../../ImGui/imgui.h"

#include "../GLM/glm.hpp"
#include "../../../Includes/Include/GLM/ext/matrix_clip_space.hpp"
#include "../../../Includes/Include/GLM/ext/matrix_transform.hpp"
#include "../../../Includes/Include/GLM/gtc/type_ptr.hpp"

namespace Fuse
{
	class EditorCamera
	{
		public:
			EditorCamera() {}
			EditorCamera(float left, float right, float bottom, float top);
			~EditorCamera();

		public:
			const glm::vec3& GetPosition() { return m_Position; }
			float GetRotation() { return m_Rotation; }

		public:
			void SetProjection(float left, float right, float bottom, float top);
			void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateMatrix(); }
			void SetRotation(float rotation) { m_Rotation = rotation; RecalculateMatrix(); }

		public:
			const glm::mat4& GetProjectionMatrix() { return m_ProjectionMatrix; }
			const glm::mat4& GetViewMatrix() { return m_ViewMatrix; }
			const glm::mat4& GetViewProjectionMatrix() { return m_ViewProjectionMatrix; }

		private:
			void RecalculateMatrix();

		private:
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ViewProjectionMatrix;

			glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};
			float m_Rotation {0.0f};
	};
}