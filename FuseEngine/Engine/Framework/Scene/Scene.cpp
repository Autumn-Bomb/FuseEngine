#include "Scene.h"

FuseEngine::Scene::Scene()
{
	m_VAO = 0;
	m_VBO = 0;
	m_ShaderProgram = 0;
	m_VertexShader = 0;
	m_FragmentShader = 0;
}
FuseEngine::Scene::~Scene() {}

void FuseEngine::Scene::SetupShaders()
{
	m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_VertexShader, 1, &m_VertexShaderSource, NULL);
	glCompileShader(m_VertexShader);

	m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_FragmentShader, 1, &m_FragmentShaderSource, NULL);
	glCompileShader(m_FragmentShader);

	CheckShaderCompilation(m_VertexShader);
	CheckShaderCompilation(m_FragmentShader);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, m_VertexShader);
	glAttachShader(m_ShaderProgram, m_FragmentShader);
	glLinkProgram(m_ShaderProgram);

	CheckShaderLink(m_ShaderProgram);

	glUseProgram(m_ShaderProgram);

	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragmentShader);
}

void FuseEngine::Scene::BindShaders()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void FuseEngine::Scene::ProcessInput()
{
	// Handle scene input
}

void FuseEngine::Scene::Render()
{
	glUseProgram(m_ShaderProgram);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void FuseEngine::Scene::CheckShaderCompilation(GLuint shader)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << shader << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void FuseEngine::Scene::CheckShaderLink(GLuint shaderProgram)
{
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << shaderProgram << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}