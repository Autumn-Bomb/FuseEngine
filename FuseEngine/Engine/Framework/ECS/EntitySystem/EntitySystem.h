#pragma once
#include "../ENTT/entt.hpp"
#include "../../../Editor/Panels/Console/Console.h"
#include "../Components/Components.h"

namespace Fuse
{
	class EntitySystem
	{
		public:
			EntitySystem() { m_World = new entt::registry(); }
			~EntitySystem() {}

		public:
			entt::entity& OnEntityAdded()
			{
				auto entity = m_World->create();

				Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Entity Added to Scene");
				
				OnComponentAdded<Fuse::Components::Entity>(entity);
				OnComponentAdded<Fuse::Components::Transform>(entity);

				return entity;
			}

			template<class T = Fuse::Component>
			void OnComponentRemoved(entt::entity& entity)
			{
				bool hasComponent = m_World->any_of<T>(entity);

				if (hasComponent)
				{
					m_World->erase<T>(entity);
					Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Component Removed");
				}
				else
				{
					Fuse::Console::PrintToConsole(Fuse::MessageType::ERROR, "Entity didn't contain component");
				}
			}

			template<class T = Fuse::Component>
			void OnComponentAdded(entt::entity& entity)
			{
				bool hasComponent = m_World->any_of<T>(entity);

				if (!hasComponent)
				{
					m_World->emplace<T>(entity);
					Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Component Added");
				}
				else
				{
					Fuse::Console::PrintToConsole(Fuse::MessageType::ERROR, "Entity already contains this component");
				}
			}

			template<typename T>
			T& GetComponent(entt::entity& entity)
			{
				bool hasComponent = m_World->any_of<T>(entity);

				if (hasComponent)
				{
					return m_World->get<T>(entity);
					Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Got Component from Entity");
				}
			}

			void OnUpdate(double deltaTime)
			{
				
			}

			void OnEntityRemoved(entt::entity& entity)
			{
				if (m_World->valid(entity))
				{
					m_World->destroy(entity);
				}
			}

			static size_t GetEntities() { return m_World->alive(); }

		private:
			inline static entt::registry* m_World;
	};
}