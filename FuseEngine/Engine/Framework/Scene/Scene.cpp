#include "Scene.h"

FuseEngine::Scene::Scene()
{
	m_VAO = 0;
	m_VBO = 0;
	m_FBO = 0;
}
FuseEngine::Scene::~Scene() {}

void FuseEngine::Scene::SetupShaders()
{
	m_ShaderProgram.LoadShader(GL_VERTEX_SHADER, "Vertex", "Engine/Framework/Graphics/Shaders/Basic/VertexShader.vert");
	m_ShaderProgram.LoadShader(GL_FRAGMENT_SHADER, "Fragment", "Engine/Framework/Graphics/Shaders/Basic/FragmentShader.frag");
	m_ShaderProgram.Link();
}

void FuseEngine::Scene::BindShaders()
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void FuseEngine::Scene::SetupFBO()
{
	glGenFramebuffers(1, &m_FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1920, 1061, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "ERROR::FRAMEBUFFER::FRAMEBUFFER_NOT_COMPLETE" << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	Render();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(m_VAO);
	glBindTexture(GL_TEXTURE_2D, m_Texture);

	glBindVertexArray(0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteFramebuffers(1, &m_FBO);
}

void FuseEngine::Scene::ProcessInput()
{
	// Handle scene input
}

void FuseEngine::Scene::Update()
{
	m_ShaderProgram.CheckShadersForChanges();
}

void FuseEngine::Scene::Render()
{
	m_ShaderProgram.Use();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}