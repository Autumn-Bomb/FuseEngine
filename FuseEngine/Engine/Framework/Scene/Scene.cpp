#include "Scene.h"

Fuse::Scene::Scene() {}
Fuse::Scene::~Scene() {}

void Fuse::Scene::Initialise()
{
	m_Renderer.InitialiseRenderer();
}

void Fuse::Scene::ProcessInput()
{
	// Handle scene input
}

void Fuse::Scene::Update() {}

void Fuse::Scene::Render()
{
	m_Renderer.Render();
}