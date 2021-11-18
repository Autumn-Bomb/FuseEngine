#include "SceneRenderer.h"

FuseEngine::SceneRenderer::SceneRenderer()
{
	m_ShaderProgram.LoadShaders("Engine/Framework/Graphics/Shaders/Basic/VertexShader.glsl", "Engine/Framework/Graphics/Shaders/Basic/FragmentShader.glsl");
	m_ShaderProgram.CreateShaders();
}
FuseEngine::SceneRenderer::~SceneRenderer() {}

void FuseEngine::SceneRenderer::SetupScene()
{
	
}

void FuseEngine::SceneRenderer::RenderScene()
{
	m_ShaderProgram.Use();
	m_ActiveScene.Render();
}