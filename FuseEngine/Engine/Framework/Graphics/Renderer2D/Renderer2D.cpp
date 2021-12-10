#define STB_IMAGE_IMPLEMENTATION
#include "Renderer2D.h"
#include <glfw3.h>

Fuse::Renderer2D::Renderer2D() {}
Fuse::Renderer2D::~Renderer2D() {}

void Fuse::Renderer2D::InitialiseRenderer()
{
	m_ShaderProgram.LoadShader(GL_VERTEX_SHADER, "Vertex", "Engine/Framework/Graphics/Shaders/Basic/VertexShader.vert");
	m_ShaderProgram.LoadShader(GL_FRAGMENT_SHADER, "Fragment", "Engine/Framework/Graphics/Shaders/Basic/FragmentShader.frag");
	m_ShaderProgram.Link();

	m_FrameBuffer.InitialiseFramebuffer(1469, 738);

	m_Camera = Fuse::EditorCamera(-1.9f, 1.9f, -1.9f, 1.9f);
	m_Camera.SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	m_PlayerSprite = Fuse::Sprite(m_ShaderProgram);
	m_Player = ResourceManager::LoadTexture("Engine/Resources/Textures/Quad/Player.png");
}

void Fuse::Renderer2D::Render()
{
	m_FrameBuffer.Bind();	
	m_ShaderProgram.SetUniformMatrix4fv("viewProjection", 1, GL_FALSE, glm::value_ptr(m_Camera.GetViewProjectionMatrix()));
	m_PlayerSprite.Render(m_Player, glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.5f), 0.0f, glm::vec4(0.0f, 0.0f, 0.0f, 255.0f));
	m_FrameBuffer.Unbind();
}