#pragma once
#include "../GLM/glm.hpp"
#include "../../../Includes/Include/GLM/ext/matrix_clip_space.hpp"
#include "../../../Includes/Include/GLM/ext/matrix_transform.hpp"
#include "../../../ImGui/imgui.h"

namespace FuseEngine
{
	class Camera
	{
		public:
			Camera() {}
			~Camera() {}

		public:
			void InitialiseCamera(const float width, const float height, FuseEngine::ShaderProgram& shaderProgram)
			{
				m_ShaderProgram = shaderProgram;

				m_Projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
				
				m_View = glm::lookAt(
					glm::vec3(0, 0, 0),
					glm::vec3(0, 0, 0),
					glm::vec3(0, 0, 0)
				);

				m_Model = glm::mat4(1.0f);
				m_View = glm::mat4(1.0f);

				m_MVP = m_Projection * m_View * m_Model;
			}

			void SetTranslation(glm::vec3 translation)
			{
				m_View = glm::translate(m_View, translation);
			}

			void RotateCamera(float speed, glm::vec3 rotationAxis)
			{
				m_Model = glm::rotate(m_Model, glm::radians(speed), rotationAxis);
			}

			void Update()
			{
				ImGui::Begin("Camera Controls");
				ImGui::Text("Camera X");
				ImGui::DragFloat("##Camera X:", &m_View[3][0], 0.1f, -100, 100);

				ImGui::Text("Camera Y");
				ImGui::DragFloat("##Camera Y:", &m_View[3][1], 0.1f, -100, 100);
				
				ImGui::Text("Camera Scale");
				ImGui::DragFloat("##Camera Scale:", &m_Model[0][0], 0.1f, 1, 100);
				ImGui::DragFloat("##Camera Scale:", &m_Model[1][1], 0.1f, 1, 100);
				ImGui::End();

				m_ShaderProgram.SetUniformMatrix4fv("model", 1, GL_FALSE, glm::value_ptr(GetModel()));
				m_ShaderProgram.SetUniformMatrix4fv("view", 1, GL_FALSE, glm::value_ptr(GetView()));
				m_ShaderProgram.SetUniformMatrix4fv("projection", 1, GL_FALSE, glm::value_ptr(GetProjection()));
			}

		public:
			glm::mat4 GetModel() { return m_Model; }
			glm::mat4 GetProjection() { return m_Projection; }
			glm::mat4 GetView() { return m_View; }

			glm::mat4 GetMVP() { return m_MVP; }

		private:
			FuseEngine::ShaderProgram m_ShaderProgram;

			glm::mat4 m_Projection;
			glm::mat4 m_View;
			glm::mat4 m_Model;
			glm::mat4 m_MVP;
	};
}