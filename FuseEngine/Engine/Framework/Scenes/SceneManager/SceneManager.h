#pragma once
#include "../BaseScene/Scene.h"
#include <unordered_map>
#include <iostream>

namespace Fuse
{
	class SceneManager
	{
		public:
			SceneManager() { m_LoadedScene = nullptr; }
			~SceneManager() {}

		public:
			void AddScene(const char* sceneName, Fuse::Scene& scene)
			{
				std::pair<const char*, Fuse::Scene&> newScene (sceneName, scene);

				m_LoadedScenes.emplace(newScene);
				m_LoadedScene = &newScene.second;

				std::cout << "Scene Added: " << sceneName;
			}

			void OnSceneLoaded()
			{
				m_LoadedScene->OnLoad();
			}

			void OnSceneUpdate(float deltaTime)
			{
				m_LoadedScene->Update(deltaTime);
			}

			void OnSceneRender()
			{
				m_LoadedScene->Render();
			}

			void OnSceneUnloaded()
			{
				m_LoadedScene->OnUnload();
			}

		private:
			 std::unordered_map<const char*, Fuse::Scene&> m_LoadedScenes;
			 Fuse::Scene* m_LoadedScene;
	};
}