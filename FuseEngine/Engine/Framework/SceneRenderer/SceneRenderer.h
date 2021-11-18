#pragma once
#include "../Scene/Scene.h"
#include "../../Framework/Graphics/ShaderProgram/ShaderProgram.h"

namespace FuseEngine
{
	class SceneRenderer
	{
		public:
			SceneRenderer();
			~SceneRenderer();

		public:
			void SetupScene();
			void RenderScene();

		public:
			FuseEngine::Scene& GetActiveScene() { return m_ActiveScene; }
			void SetActiveScene(FuseEngine::Scene& activeScene) { m_ActiveScene = activeScene; }

		private:
			FuseEngine::Scene m_ActiveScene;
			FuseEngine::ShaderProgram m_ShaderProgram;
	};
}