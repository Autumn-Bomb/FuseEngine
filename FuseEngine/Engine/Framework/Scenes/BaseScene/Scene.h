#pragma once

namespace Fuse
{
	class Scene
	{
		public:
			Scene() { m_SceneName = ""; }
			~Scene() {}

		public:
			virtual void OnLoad() {}
			virtual void Update(float deltaTime) {}
			virtual void Render() {}
			virtual void OnUnload() {}

		public:
			const char* GetSceneName() { return m_SceneName; }

		private:
			const char* m_SceneName;
	};
}