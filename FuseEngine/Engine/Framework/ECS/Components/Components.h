#pragma once
#include "../GLM/glm.hpp"
#include "../GLM/gtx/matrix_decompose.hpp"
#include "../../../../Includes/Include/GLM/ext/matrix_transform.hpp"

namespace Fuse
{
	class Component
	{
		public:
			std::string m_ComponentName;
			bool m_IsActive;
	};

	class Components
	{
		public:
			Components() {}
			~Components() {}

		public:
			struct Entity : Component
			{
				public:
					Entity() { m_ComponentName = "Transform"; m_IsActive = true; }
					~Entity() {}

				public:
					void SetEntityName(std::string entityName) { m_EntityName = entityName; }
					void SetEntityTag(std::string entityTag) { m_EntityTag = entityTag; }

				public:
					std::string GetEntityName() { return m_EntityName; }
					std::string GetEntityTag() { return m_EntityTag; }

				public:
					std::string m_EntityName = "Test Name";
					std::string m_EntityTag = "Entity";
			};

			struct Transform : Component
			{
				public:
					Transform() { m_ComponentName = "Transform"; m_IsActive = true; }
					~Transform() {}

				public:
					void SetPosition(glm::vec2 position) { m_Transform = glm::translate(m_Transform, glm::vec3(position.x, position.y, 0.0f)); }
					void SetRotation(float rotation) { m_Transform = glm::rotate(m_Transform, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f)); }

				public:
					glm::vec3& GetTranslation() const { glm::vec3 translation = m_Transform[3]; return translation; }

				private:
					glm::mat4 m_Transform;

				private:
					glm::vec3 m_Translation;
					glm::vec3 m_Scale;
			};

			struct SpriteRenderer2D : Component
			{
				public:
					SpriteRenderer2D() { m_ComponentName = "Sprite Renderer2D"; m_IsActive = true; }
					~SpriteRenderer2D() {}

				public:
					uint32_t GetTexture() { return m_Texture; }
					bool GetIsVisible() { return m_IsVisible; }

					void SetTexture(uint32_t texture) { m_Texture = texture; }
					void SetIsVisble(bool visible) { m_IsVisible = visible; }

				private:
					uint32_t m_Texture;
					bool m_IsVisible;
			};

			struct BoxCollider2D : Component
			{
				public:
					BoxCollider2D() { m_ComponentName = "BoxCollider2D"; m_IsActive = true; }
					~BoxCollider2D() {}

				public:
					bool GetColliderActive() { return m_Active; }
					glm::vec2 const GetColliderBounds() { return m_ColliderBounds; }

					void SetColliderBounds(glm::vec2 colliderBounds) { m_ColliderBounds = colliderBounds; }
					void SetActive(bool active) { m_Active = active; }

				private:
					bool m_Active;
					glm::vec2 m_ColliderBounds;
			};
	};
}