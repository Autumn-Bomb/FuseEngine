#pragma once
#include "glad.h"

#include "../../../ImGui/imgui.h"
#include "../Graphics/Renderer2D/Renderer2D.h"
#include <iostream>

namespace Fuse
{
	class Scene
	{
		public:
			Scene();
			~Scene();

		public:
			void Initialise();
			void ProcessInput();
			void Update();
			void Render();

		public:
			Fuse::Renderer2D& GetRenderer() { return m_Renderer; }

		private:
			Fuse::Renderer2D m_Renderer;
	};
}