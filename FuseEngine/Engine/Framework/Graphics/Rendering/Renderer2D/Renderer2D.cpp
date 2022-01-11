#define STB_IMAGE_IMPLEMENTATION
#include "Renderer2D.h"

Fuse::Renderer2D::Renderer2D() {}
Fuse::Renderer2D::~Renderer2D() {}

void Fuse::Renderer2D::InitialiseRenderer(Fuse::EditorCamera& camera)
{
	m_EditorCamera = camera;

	m_FrameBuffer.InitialiseFramebuffer(1469, 738);
	InitialiseBuffers();
}

void Fuse::Renderer2D::InitialiseBuffers()
{
	glGenVertexArrays(1, &m_Quad.m_QuadVAO);
	glGenBuffers(1, &m_Quad.m_QuadVBO);
	glGenBuffers(1, &m_Quad.m_QuadEBO);

	glBindVertexArray(m_Quad.m_QuadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_Quad.m_QuadVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Quad.m_QuadEBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Quad.m_Vertices), m_Quad.m_Vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Quad.indices), m_Quad.indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Fuse::Renderer2D::Bind()
{
	m_DrawCalls = 0;
	m_FrameBuffer.Bind();
}

void Fuse::Renderer2D::DrawSprite(uint32_t texture, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour)
{
	m_Quad.m_QuadTexture = texture;
	glBindTexture(GL_TEXTURE_2D, m_Quad.m_QuadTexture);

	m_Transform = glm::mat4(1.0f);
	m_Transform = glm::translate(m_Transform, glm::vec3(position.x, position.y, 1.0f));
	m_Transform = glm::rotate(m_Transform, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	m_Transform = glm::scale(m_Transform, glm::vec3(size.x, size.y, 1.0f));

	Fuse::ResourceManager::GetShaderProgram().Use();
	Fuse::ResourceManager::GetShaderProgram().SetUniformMatrix4fv("transform", 1, GL_FALSE, glm::value_ptr(m_Transform));

	glBindVertexArray(m_Quad.m_QuadVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	++m_DrawCalls;
}

void Fuse::Renderer2D::DrawSpriteBatched(uint32_t originTexture, int x, int y, int width, int height, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour)
{
	++m_DrawCalls;
}

void Fuse::Renderer2D::Unbind()
{
	m_FrameBuffer.Unbind();
}