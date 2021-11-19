#pragma once

#include "../../../Framework/Panels/BasePanel/BasePanel.h"

#include <iostream>

namespace FuseEngine
{
	class Profiler : public FuseEngine::BasePanel
	{
		public:
			Profiler();
			~Profiler();

		public:
			void OnImGuiRender() override;
			void PrintStatsToConsole();

		private:
			bool statsPrinted = false;
			const GLubyte* m_Vendor;
			const GLubyte* m_Renderer;
			const GLubyte* m_OpenGlVersion;

			float m_FPS;
			float m_Frametime;
	};
}