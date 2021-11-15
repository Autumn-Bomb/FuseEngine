#pragma once
#include "../../../ImGui/imgui.h"

namespace FuseEngine
{
	class Menubar
	{
		public:
			Menubar();
			~Menubar();

		public:
			void OnImGuiRender();
	};
}