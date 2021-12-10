#pragma once
#include "../../../ImGui/imgui.h"

namespace Fuse
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