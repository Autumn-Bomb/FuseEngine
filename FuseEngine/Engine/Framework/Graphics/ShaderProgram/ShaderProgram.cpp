#include "ShaderProgram.h"

FuseEngine::ShaderProgram::ShaderProgram()
{
	m_FragmentShader = 0;
	m_VertexShader = 0;
	m_VertexShaderCode = "";
	m_FragmentShaderCode = "";
	m_ShaderProgramID = 0;
}
FuseEngine::ShaderProgram::~ShaderProgram() {}

void FuseEngine::ShaderProgram::LoadShaders(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	std::string m_VertexCode;
	std::string m_FragmentCode;

	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	try
	{
		vertexShaderFile.open(vertexShaderPath);
		fragmentShaderFile.open(fragmentShaderPath);

		std::stringstream vertexShaderStream, fragmentShaderStream;

		vertexShaderStream << vertexShaderFile.rdbuf();
		fragmentShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		m_VertexCode = vertexShaderStream.str();
		m_FragmentCode = fragmentShaderStream.str();
	}
	catch (std::ofstream::failure e)
	{
		std::cout << "ERROR: SHADER FILE NOT SUCCESSFULLY READ" << std::endl;
	}

	m_VertexShaderCode = m_VertexCode.c_str();
	m_FragmentShaderCode = m_FragmentCode.c_str();
}

void FuseEngine::ShaderProgram::CreateShaders()
{
	m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_VertexShader, 1, &m_VertexShaderCode, NULL);
	glCompileShader(m_VertexShader);
	CheckShaderCompilation(m_VertexShader, "VERTEX SHADER");

	m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_FragmentShader, 1, &m_FragmentShaderCode, NULL);
	glCompileShader(m_FragmentShader);
	CheckShaderCompilation(m_FragmentShader, "FRAGMENT SHADER");

	m_ShaderProgramID = glCreateProgram();
	glAttachShader(m_ShaderProgramID, m_VertexShader);
	glAttachShader(m_ShaderProgramID, m_FragmentShader);
	glLinkProgram(m_ShaderProgramID);
	CheckShaderLink(m_ShaderProgramID);

	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragmentShader);
}

void FuseEngine::ShaderProgram::Use()
{
	glUseProgram(m_ShaderProgramID);
}

void FuseEngine::ShaderProgram::CheckShaderCompilation(GLuint shader, const char* shaderName)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED::" << shaderName << ": " << infoLog << std::endl;
	}
}

void FuseEngine::ShaderProgram::CheckShaderLink(GLuint shaderProgram)
{
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED - " << infoLog << std::endl;
	}
}

void FuseEngine::ShaderProgram::SetBool(const std::string& name, bool value)
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void FuseEngine::ShaderProgram::SetInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void FuseEngine::ShaderProgram::SetFloat(const std::string& name, float value)
{
	glUniform1f(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}