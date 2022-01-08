#pragma once
#include "../../Input/Input.h"
#include "../../EditorCamera/EditorCamera.h"

namespace Fuse
{
	class EditorCameraController
	{
		public:
			EditorCameraController();
			EditorCameraController(float left, float right, float bottom, float top);
			~EditorCameraController();

		public:
			void Update();

		public:
			Fuse::EditorCamera* GetCamera() { return m_EditorCamera; }

		private:
			std::vector<int> m_TrackedKeys;
			
		private:
			float m_MovementDistance;
			float m_MovementSpeed;

		private:
			Fuse::EditorCamera* m_EditorCamera;
			Fuse::Input* m_Input;
	};
}