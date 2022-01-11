#pragma once
#include "../Graphics/Rendering/Renderer2D/Renderer2D.h"
#include "../EditorCamera/EditorCameraController/EditorCameraController.h"
#include "../../../Includes/Include/JSON/json.hpp"
#include "../ECS/EntitySystem/EntitySystem.h"

namespace Fuse
{
	class Scene
	{
		public:
			Scene() {}
			Scene(std::string name) { m_SceneName = name; }
			~Scene() {}

		public:
			void OnSceneLoaded()
			{
				m_CameraController = Fuse::EditorCameraController(-1.6f, 1.6f, -0.9f, 0.9f);

				Fuse::Renderer2D::InitialiseRenderer(*m_CameraController.GetCamera());

				std::cout << "Scene Loaded: " << m_SceneName << std::endl;
				Fuse::ResourceManager::LoadShader("Vertex", GL_VERTEX_SHADER, "Engine/Resources/Shaders/Base/VertexShader.vert");
				Fuse::ResourceManager::LoadShader("Fragment", GL_FRAGMENT_SHADER, "Engine/Resources/Shaders/Base/FragmentShader.frag");
				Fuse::ResourceManager::LinkShaders();
			}

			void OnSceneInput(double deltaTime)
			{
				m_CameraController.HandleInput(deltaTime);
			}

			void OnSceneUpdate(double deltaTime)
			{
				m_EntitySystem.OnUpdate(deltaTime);
			}

			void OnRenderScene()
			{
				Fuse::Renderer2D::Bind();
				Fuse::ResourceManager::GetShaderProgram().SetUniformMatrix4("viewProjection", m_CameraController.GetCamera()->GetProjectionViewMatrix());

				Fuse::Renderer2D::Unbind();
			}

			void OnSceneUnloaded()
			{
				
			}

		public:
			Fuse::Renderer2D& GetRenderer() { return m_Renderer; }
			Fuse::EntitySystem& GetEntitySystem() { return m_EntitySystem; }

		private:
			std::string m_SceneName;

		private:
			Fuse::EntitySystem m_EntitySystem;
			Fuse::Renderer2D m_Renderer;
			Fuse::EditorCameraController m_CameraController;
	};
}