#define STB_IMAGE_IMPLEMENTATION
#include "Renderer2D.h"
#include <glfw3.h>

FuseEngine::Renderer2D::Renderer2D() {}
FuseEngine::Renderer2D::~Renderer2D() {}

void FuseEngine::Renderer2D::InitialiseRenderer()
{
	m_ShaderProgram.LoadShader(GL_VERTEX_SHADER, "Vertex", "Engine/Framework/Graphics/Shaders/Basic/VertexShader.vert");
	m_ShaderProgram.LoadShader(GL_FRAGMENT_SHADER, "Fragment", "Engine/Framework/Graphics/Shaders/Basic/FragmentShader.frag");
	m_ShaderProgram.Link();

	m_FrameBuffer.InitialiseFramebuffer(1920, 1061);

	m_Camera.InitialiseCamera(1920, 1061, m_ShaderProgram);
	m_Camera.SetTranslation(glm::vec3(0.0f, 0.0f, 0.0f));

	m_BackgroundSprite = FuseEngine::Sprite(m_ShaderProgram);
	m_Background = ResourceManager::LoadTexture("Engine/Resources/Textures/Quad/Background.png");

	m_MiddlegroundSprite = FuseEngine::Sprite(m_ShaderProgram);
	m_Middleground = ResourceManager::LoadTexture("Engine/Resources/Textures/Quad/Middleground.png");
}

void FuseEngine::Renderer2D::Render()
{
	m_FrameBuffer.FirstPass();		
	m_BackgroundSprite.Render(m_Background, glm::vec2(0.0f, 0.0f), glm::vec2(4.0f, 4.0f), 0.0f, glm::vec4(0.0f, 0.0f, 0.0f, 255.0f));
	m_MiddlegroundSprite.Render(m_Middleground, glm::vec2(0.0f, 0.0f), glm::vec2(4.0f, 4.0f), 0.0f, glm::vec4(0.0f, 0.0f, 0.0f, 255.0f));
	m_FrameBuffer.LastPass();

	m_Camera.Update();
}