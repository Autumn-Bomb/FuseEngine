#pragma once
#include <vector>
#include "../Components/Components.h"

namespace Fuse
{
	class Entity
	{
		public:
			Entity() { m_EntityID = rand() % 100 + 1; }
			~Entity() {}

		public:
			template <class T>
			void AddComponent(T component) { m_Components.emplace_back(T); }

		private:
			uint32_t m_EntityID;

		private:
			std::vector<Fuse::Components> m_Components;
	};
}