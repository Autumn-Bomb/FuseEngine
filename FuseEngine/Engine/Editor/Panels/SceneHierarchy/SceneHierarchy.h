#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"
#include "../../../Framework/SceneManager/SceneManager.h"

namespace Fuse
{
	class SceneHierarchy : public Fuse::Panel
	{
		public:
			SceneHierarchy();
			~SceneHierarchy();

		public:
			void OnImGuiRender() override;

		private:
			int m_EntityCount;
			entt::entity m_SelectedEntity;

			std::vector<entt::entity> m_Entities;
			Fuse::EntitySystem* m_EntitySystem;
	};
}