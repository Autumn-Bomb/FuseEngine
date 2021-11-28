#include "ShaderProgram.h"

FuseEngine::ShaderProgram::ShaderProgram()
{
	m_FragmentShader = 0;
	m_VertexShader = 0;
	m_ComputeShader = 0;
	m_ShaderProgramID = 0;

	m_VertexShaderCode = "";
	m_FragmentShaderCode = "";
	m_ComputeShaderCode = "";

	m_Timer.Start();
}
FuseEngine::ShaderProgram::~ShaderProgram() {}

void FuseEngine::ShaderProgram::LoadShader(GLuint shaderType, const char* name, const char* shaderPath)
{
	std::ifstream shaderFile;

	try
	{
		std::stringstream shaderStream;

		shaderFile.open(shaderPath);
		shaderStream << shaderFile.rdbuf();

		if (shaderType == GL_VERTEX_SHADER)
		{
			m_VertexCode = shaderStream.str();
			m_VertexShaderCode = m_VertexCode.c_str();
		}
		else if (shaderType == GL_FRAGMENT_SHADER)
		{
			m_FragmentCode = shaderStream.str();
			m_FragmentShaderCode = m_FragmentCode.c_str();
		}

		shaderFile.close();

		m_ShaderCache[name] = shaderPath;
		CreateShader(shaderType);
	}
	catch (std::ofstream::failure e)
	{
		std::cout << "ERROR: SHADER FILE NOT SUCCESSFULLY READ" << std::endl;
	}
}

void FuseEngine::ShaderProgram::CreateShader(GLuint shaderType)
{
	if(shaderType == GL_VERTEX_SHADER)
	{
		m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(m_VertexShader, 1, &m_VertexShaderCode, NULL);
		glCompileShader(m_VertexShader);
		
		if (CheckShaderCompilation(m_VertexShader, "VERTEX"))
		{
			m_Shaders.emplace_back(m_VertexShader);
		}
	}
	else if(shaderType == GL_FRAGMENT_SHADER)
	{
		m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(m_FragmentShader, 1, &m_FragmentShaderCode, NULL);
		glCompileShader(m_FragmentShader);
		
		if (CheckShaderCompilation(m_FragmentShader, "FRAGMENT"))
		{
			m_Shaders.emplace_back(m_FragmentShader);
		}
	}
	else if(shaderType == GL_COMPUTE_SHADER)
	{ 
		m_ComputeShader = glCreateShader(GL_COMPUTE_SHADER);
		glShaderSource(m_ComputeShader, 1, &m_ComputeShaderCode, NULL);
		glCompileShader(m_ComputeShader);

		if (CheckShaderCompilation(m_ComputeShader, "COMPUTE"))
		{
			m_Shaders.emplace_back(m_ComputeShader);
		}
	}
}

void FuseEngine::ShaderProgram::Link()
{
	m_ShaderProgramID = glCreateProgram();

	for (auto shader : m_Shaders)
	{
		glAttachShader(m_ShaderProgramID, shader);
	}
	
	glLinkProgram(m_ShaderProgramID);
	
	if (CheckShaderLink(m_ShaderProgramID))
	{
		for (auto shader : m_Shaders)
		{
			glDeleteShader(shader);
		}
	}
}

void FuseEngine::ShaderProgram::Use()
{
	glUseProgram(m_ShaderProgramID);
}

bool FuseEngine::ShaderProgram::CheckShaderCompilation(GLuint shader, const char* shaderName)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED::" << shaderName << ": " << infoLog << std::endl;
		return false;
	}
	else
	{ 
		std::cout << "SUCCESS::SHADER::COMPILATION_COMPLETED::" << shaderName << std::endl;
		return true;
	}
}

bool FuseEngine::ShaderProgram::CheckShaderLink(GLuint shaderProgram)
{
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINK_FAILED: " << infoLog << std::endl;
		return false;
	}
	else
	{
		std::cout << "SUCCESS::SHADER::LINK_COMPLETED " << std::endl;
		return true;
	}
}

void FuseEngine::ShaderProgram::CheckShadersForChanges()
{
	if (m_Timer.elapsedTime() >= m_RefreshTime)
	{
		ShaderChanged();
		m_Timer.Restart();
	}
}

void FuseEngine::ShaderProgram::ShaderChanged()
{
	/* Load in new shader file, compare current stored file to new loaded file
	   if they're the same, skip over. If they're not, load in the new file and rebind shaders
	*/
}

void FuseEngine::ShaderProgram::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void FuseEngine::ShaderProgram::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void FuseEngine::ShaderProgram::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}