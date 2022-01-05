#include "Sprite.h"

Fuse::Sprite::Sprite() {}
Fuse::Sprite::Sprite(Fuse::ShaderProgram& shaderProgram)
{
	m_ShaderProgram = shaderProgram; 

	glGenVertexArrays(1, &m_QuadVAO);
	glGenBuffers(1, &m_QuadVBO);
	glGenBuffers(1, &m_QuadEBO);

	glBindVertexArray(m_QuadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_QuadVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_QuadEBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
Fuse::Sprite::~Sprite() {}

void Fuse::Sprite::Render(uint32_t texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec4 color)
{
	m_QuadTexture = texture;
	
	glBindTexture(GL_TEXTURE_2D, m_QuadTexture);
	m_Transform = glm::mat4(1.0f);

	m_Transform = glm::translate(m_Transform, glm::vec3(position.x, position.y, 1.0f));
	m_Transform = glm::rotate(m_Transform, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
	m_Transform = glm::scale(m_Transform, glm::vec3(size.x, size.y, 1.0f));

	m_ShaderProgram.Use();
	m_ShaderProgram.SetUniformMatrix4fv("transform", 1, GL_FALSE, glm::value_ptr(m_Transform));

	glBindVertexArray(m_QuadVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}