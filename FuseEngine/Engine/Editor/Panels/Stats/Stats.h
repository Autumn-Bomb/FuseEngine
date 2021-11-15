#pragma once

#include "../../../Framework/Panels/BasePanel/BasePanel.h"

#include <iostream>

namespace FuseEngine
{
	class Stats : public FuseEngine::BasePanel
	{
		public:
			Stats();
			~Stats();

		public:
			void OnImGuiRender() override;
			void PrintStatsToConsole();

		private:
			bool statsPrinted = false;
			const GLubyte* m_Vendor;
			const GLubyte* m_Renderer;
			const GLubyte* m_OpenGlVersion;
	};
}