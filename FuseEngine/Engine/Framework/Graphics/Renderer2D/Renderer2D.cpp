#define STB_IMAGE_IMPLEMENTATION
#include "Renderer2D.h"

int Fuse::Renderer2D::m_DrawCalls = 0;

Fuse::Renderer2D::Renderer2D() {}
Fuse::Renderer2D::~Renderer2D() {}

void Fuse::Renderer2D::InitialiseRenderer(Fuse::ShaderProgram& shaderProgram)
{
	m_ShaderProgram = shaderProgram;
	m_FrameBuffer.InitialiseFramebuffer(1469, 738);
}

void Fuse::Renderer2D::Bind()
{
	m_DrawCalls = 0;
	m_FrameBuffer.Bind();
}

void Fuse::Renderer2D::DrawSprite(Fuse::Sprite& sprite, uint32_t texture, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour)
{
	sprite.Render(texture, position, size, rotation, colour);
	++m_DrawCalls;     
}

void Fuse::Renderer2D::DrawSpriteBatched(Fuse::Sprite& sprite, uint32_t originTexture, int x, int y, int width, int height, glm::vec3 position, glm::vec3 size, float rotation, glm::vec4 colour)
{

	++m_DrawCalls;
}

void Fuse::Renderer2D::Unbind()
{
	m_FrameBuffer.Unbind();
}