#pragma once
#include "../Graphics/Rendering/Renderer2D/Renderer2D.h"
#include "../EditorCamera/EditorCameraController/EditorCameraController.h"
#include "../../../Includes/Include/JSON/json.hpp"

namespace Fuse
{
	class Scene1
	{
		public:
			Scene1() { m_SceneName = ""; m_Texture = 0; }
			Scene1(const char* name) { m_SceneName = name; m_Texture = 0; }
			~Scene1() {}

		public:
			void OnSceneLoaded()
			{
				m_CameraController = Fuse::EditorCameraController(-1.6f, 1.6f, -0.9f, 0.9f);

				Fuse::Renderer2D::InitialiseRenderer(*m_CameraController.GetCamera());

				std::cout << "Scene Loaded: " << m_SceneName << std::endl;
				Fuse::ResourceManager::LoadShader("Vertex", GL_VERTEX_SHADER, "Engine/Resources/Shaders/Base/VertexShader.vert");
				Fuse::ResourceManager::LoadShader("Fragment", GL_FRAGMENT_SHADER, "Engine/Resources/Shaders/Base/FragmentShader.frag");
				Fuse::ResourceManager::LinkShaders();

				m_Texture = Fuse::ResourceManager::LoadTexture("Engine/Resources/Textures/Player.png");	
			}

			void OnSceneInput(double deltaTime)
			{
				m_CameraController.HandleInput(deltaTime);
			}

			void OnSceneUpdate(double deltaTime)
			{

			}

			void OnRenderScene()
			{
				Fuse::Renderer2D::Bind();

				Fuse::Renderer2D::DrawSprite(m_Texture, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));			
				Fuse::ResourceManager::GetShaderProgram().SetUniformMatrix4("viewProjection", m_CameraController.GetCamera()->GetProjectionViewMatrix());

				Fuse::Renderer2D::Unbind();
			}

			void OnSceneUnloaded()
			{

			}

		public:
			Fuse::Renderer2D& GetRenderer() { return m_Renderer; }

		private:
			const char* m_SceneName;

		private:
			Fuse::Renderer2D m_Renderer;
			Fuse::EditorCameraController m_CameraController;

		private:
			uint32_t m_Texture;
	};
}