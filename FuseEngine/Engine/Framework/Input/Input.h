#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <glfw3.h>
#include <string>
#include <iostream>

namespace Fuse
{
	class Input
	{
	public:
			Input() { m_IsEnabled = true; }
			Input(std::vector<int> keysToTrack);
			~Input();

		public:
			bool GetKeyDown(int key);
			void SetKeyDown(int key, bool status);

		public:
			bool GetIsEnabled() { return m_IsEnabled; }
			bool SetIsEnabled(bool enabled) { m_IsEnabled = enabled; }
				
		public:
			static void Initialise(GLFWwindow* window);

		private:
			std::map<int, bool> m_Keys;
			bool m_IsEnabled;

		private:
			static void Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static std::vector<Input*> m_Instances;
	};
}