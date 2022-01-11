#include "SceneHierarchy.h"

Fuse::SceneHierarchy::SceneHierarchy()
{
	m_EntitySystem = &Fuse::SceneManager::GetEntitySystem();
	m_EntityCount = 0;
}

Fuse::SceneHierarchy::~SceneHierarchy() {}

void Fuse::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());

	// Loop through all entities in a scene and add them to the Hierarchy, also allow the addition of new entities through a drop down menu on button click
	if (ImGui::Button("+", ImVec2(25, 20)))
	{
		auto entity = m_EntitySystem->OnEntityAdded();
		m_EntityCount++;

		Fuse::Components::Entity& component = m_EntitySystem->GetComponent<Fuse::Components::Entity>(entity);

		std::string entityName = component.GetEntityName();
		entityName.append(" " + std::to_string(m_EntityCount));

		component.SetEntityName(entityName);
		component.SetEntityTag("Entity");

		m_Entities.emplace_back(entity);
	}

	ImGui::Separator();

	if (Fuse::SceneManager::GetEntitySystem().GetEntities() > 0)
	{
		for (auto entity : m_Entities)
		{
			auto entityName = m_EntitySystem->GetComponent<Fuse::Components::Entity>(entity);
			
			if (ImGui::TreeNode(entityName.GetEntityName().c_str()))
			{
				ImGui::TreePop();
			}
		}
	}

	ImGui::End();
}