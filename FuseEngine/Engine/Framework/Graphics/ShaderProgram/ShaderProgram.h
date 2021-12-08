#pragma once
#include "glad.h"

#include <iostream>
#include <unordered_map>

#include <vector>
#include <sstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <filesystem>

namespace FuseEngine
{
	class ShaderProgram
	{
		public:
			ShaderProgram();
			~ShaderProgram();

		public:
			void LoadShader(GLuint shaderType, const char* name, const char* path);
			void CreateShader(GLuint shaderType);
			void Link();
			void Use();

		public:
			bool CheckShaderCompilation(GLuint shader, const char* shaderName);
			bool CheckShaderLink(GLuint shaderProgram);

		public:
			void SetBool(const std::string& name, bool value) const;
			void SetInt(const std::string& name, int value) const;
			void SetFloat(const std::string& name, float value) const;
			void SetUniformMatrix4fv(const char* uniformName, GLsizei count, GLboolean transpose, const GLfloat* value);

		public:
			uint32_t GetActiveShaderProgram() { return m_ShaderProgramID; }

		private:
			std::vector<uint32_t> m_Shaders;

			std::string m_VertexCode;
			std::string m_FragmentCode;

			uint32_t m_VertexShader;
			uint32_t m_ComputeShader;
			uint32_t m_FragmentShader;
			uint32_t m_ShaderProgramID;

			const char* m_VertexShaderCode;
			const char* m_FragmentShaderCode;
			const char* m_ComputeShaderCode;
	};
}