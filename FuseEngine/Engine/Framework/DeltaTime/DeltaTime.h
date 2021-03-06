#pragma once
#include <glfw3.h>

namespace Fuse
{
	class DeltaTime
	{
		public:
			DeltaTime()
			{
				m_DeltaTime = 0.0f;
				m_LastFrame = 0.0f;
			}
			~DeltaTime() {}

		public:
			static double GetDeltaTime()
			{
				return m_DeltaTime;
			}

			static void CalculateDeltaTime()
			{
				m_CurrentFrame = glfwGetTime();
				m_DeltaTime = m_CurrentFrame - m_LastFrame;
				m_LastFrame = m_CurrentFrame;
			}

		private:
			inline static double m_CurrentFrame;
			inline static double m_DeltaTime;
			inline static double m_LastFrame;
	};
}