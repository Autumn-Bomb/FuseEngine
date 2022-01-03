#pragma once
#include "../GLM/glm.hpp"
#include "../../../../Includes/Include/GLM/ext/matrix_transform.hpp"

namespace Fuse
{
	class Components
	{
		public:
			Components() {}
			~Components() {}

		public:
			struct Transform
			{
				public:
					void SetPosition(glm::vec2 position) { m_Transform = glm::translate(m_Transform, glm::vec3(position.x, position.y, 0.0f)); }
					void SetRotation(float rotation) { m_Transform = glm::rotate(m_Transform, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f)); }

			private:
					glm::mat4 m_Transform;
			};

			struct SpriteRenderer2D
			{
				public:
					void SetTexture(uint32_t texture) { m_Texture = texture; }
					void SetIsVisble(bool visible) { m_IsVisible = visible; }

				private:
					uint32_t m_Texture;
					bool m_IsVisible;
			};

			struct BoxCollider2D
			{
				public:
					void SetColliderBounds(glm::vec2 colliderBounds) { m_ColliderBounds = colliderBounds; }
					void SetActive(bool active) { m_Active = active; }

				private:
					bool m_Active;
					glm::vec2 m_ColliderBounds;
			};

			struct Rigidbody2D
			{

			};
	};
}