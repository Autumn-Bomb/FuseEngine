#pragma once
#include "../Graphics/Rendering/Renderer2D/Renderer2D.h"
#include "../EditorCamera/EditorCameraController/EditorCameraController.h"

namespace Fuse
{
	class TestScene
	{
		public:
			TestScene()
			{
				t_Background = 0;
				t_PlayerTexture = 0;
				t_PipesTexture = 0;
				t_GridTexture = 0;

				m_SceneName = "";
			}

			TestScene(const char* sceneName)
			{
				t_Background = 0;
				t_PlayerTexture = 0;
				t_PipesTexture = 0;
				t_GridTexture = 0;

				m_SceneName = sceneName;

				m_EditorCameraController = Fuse::EditorCameraController(-1.6f, 1.6f, -0.9f, 0.9f);
			}

			void InitialiseScene()
			{
				Fuse::Renderer2D::InitialiseRenderer(*m_EditorCameraController.GetCamera());

				Fuse::ResourceManager::LoadShader("VERTEX", GL_VERTEX_SHADER, "Engine/Framework/Graphics/Shaders/Basic/VertexShader.vert");
				Fuse::ResourceManager::LoadShader("FRAGMENT", GL_FRAGMENT_SHADER, "Engine/Framework/Graphics/Shaders/Basic/FragmentShader.frag");
				Fuse::ResourceManager::LinkShaders();

				t_Background = Fuse::ResourceManager::LoadTexture("Engine/Resources/Textures/Quad/Background.png");
				t_PlayerTexture = Fuse::ResourceManager::LoadTexture("Engine/Resources/Textures/Quad/Player.png");
				t_PipesTexture = Fuse::ResourceManager::LoadTexture("Engine/Resources/Textures/Quad/Pipes.png");

				std::cout << "Scene Intialised!" << std::endl;
			}
			 
			void Input() {}

			void Update()
			{
				m_EditorCameraController.Update();
			}

			void Render()
			{
				Fuse::Renderer2D::Bind();

				Fuse::Renderer2D::DrawSprite(t_Background, { -0.5f, -0.5f, 0 }, { 2.2f, 2.0f, 1 }, 0, glm::vec4(1, 1, 1, 1));
				Fuse::Renderer2D::DrawSprite(t_PipesTexture, { 0, -0.4f, 0 }, { 1, 1.7f, 1 }, 0, glm::vec4(1, 1, 1, 1));
				Fuse::Renderer2D::DrawSprite(t_PipesTexture, { -0.5f, -0.4f, 0 }, { 1, 1.7f, 1 }, 0, glm::vec4(1, 1, 1, 1));
				Fuse::Renderer2D::DrawSprite(t_PlayerTexture, { -0.7f, -0.3f, 0 }, { 0.2f, 0.3f, 0.1f }, 0, glm::vec4(1, 1, 1, 1));

				Fuse::ResourceManager::GetShaderProgram().SetUniformMatrix4("viewProjection", m_EditorCameraController.GetCamera()->GetProjectionViewMatrix());

				Fuse::Renderer2D::Unbind();
			}

		public:
			Fuse::Renderer2D& GetRenderer() { return m_Renderer; }
			const char* GetSceneName() { return m_SceneName; }

		private:
			Fuse::Renderer2D m_Renderer;
			Fuse::EditorCameraController m_EditorCameraController;

			const char* m_SceneName = "Test Scene";

		private:
			uint32_t t_GridTexture;

			uint32_t t_PlayerTexture;
			uint32_t t_PipesTexture;
			uint32_t t_Background;
	};
}