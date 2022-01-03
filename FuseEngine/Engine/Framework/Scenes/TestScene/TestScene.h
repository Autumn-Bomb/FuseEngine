#pragma once

#include "../BaseScene/Scene.h"
#include <glad.h>
#include <iostream>

namespace Fuse
{
	class TestScene : public Fuse::Scene
	{
		public:
			TestScene() {}
			~TestScene() {}

		public:
			void OnLoad() override
			{
				std::cout << "\nLOADING SCENE" << std::endl;
			}

			void Update(float deltaTime) override
			{
				std::cout << "UPDATING SCENE" << std::endl;
			}

			void Render() override
			{
				glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				std::cout << "RENDERING SCENE" << std::endl;
			}

			void OnUnload() override
			{
				std::cout << "UNLOADING SCENE" << std::endl;
			}
	};
}