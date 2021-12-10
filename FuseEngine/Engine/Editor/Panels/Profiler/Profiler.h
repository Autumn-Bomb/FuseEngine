#pragma once

#include "../../../Framework/Panels/BasePanel/BasePanel.h"

#include <iostream>

namespace Fuse
{
	class Profiler : public Fuse::BasePanel
	{
		public:
			Profiler();
			~Profiler();

		public:
			void OnImGuiRender() override;
			void PrintStatsToConsole();

		public:
			void SetFPS(int fps) { m_FPS = fps; }
			void SetFrametime(double frameTime) { m_Frametime = frameTime; }
			void SetDrawcalls(int drawCalls) { m_Drawcalls = drawCalls; }
		
		private:
			bool statsPrinted = false;
			const GLubyte* m_Vendor;
			const GLubyte* m_Renderer;
			const GLubyte* m_OpenGlVersion;

			int m_FPS;
			int m_Drawcalls;
			double m_Frametime;
	};
}