#pragma once

#include "../BaseLayer/BaseLayer.h"
#include "../../Input/Input.h"

namespace Fuse
{
	class InputLayer : public Layer
	{
		public:
			InputLayer() { m_Input = nullptr; }
			~InputLayer() {}

		public:
			void InitialiseCallback(GLFWwindow* window)
			{
				m_Input->InitialiseCallback(window);
			}

			void AddTrackedKeys()
			{
				for (int i = 0; i < 256; ++i)
				{
					m_TrackedKeys.emplace_back(i);
				}
			}

			void OnCreate() override
			{
				AddTrackedKeys();
				m_Input = new Fuse::Input(m_TrackedKeys);

				std::cout << "Input Layer Created!" << std::endl;
			}

			void OnUpdate() override
			{
				if (m_Input->GetKeyDown('W'))
				{
					std::cout << "Input Layer[Key Pressed]: W" << std::endl;
				}
			}

			void PrintKeyPressed(int key)
			{
				std::cout << "Input Layer[Key Pressed]: " << static_cast<char>(key - 'a') << std::endl;
			}

			void OnDestroy() override
			{
				delete m_Input;
				std::cout << "Input Layer Destroyed!" << std::endl;
			}

		private:
			std::vector<int> m_TrackedKeys;

		private:
			Fuse::Input* m_Input;
	};
}