#pragma once
#include "glad.h"
#include <fstream>
#include <sstream>

#include <iostream>

namespace FuseEngine
{
	class ShaderProgram
	{
		public:
			ShaderProgram();
			~ShaderProgram();

		public:
			void LoadShaders(const char* vertex, const char* fragment);
			void CreateShaders();
			void Use();

		public:
			void CheckShaderCompilation(GLuint shader, const char* shaderName);
			void CheckShaderLink(GLuint shaderProgram);

		public:
			void SetBool(const std::string& name, bool value);
			void SetInt(const std::string& name, int value);
			void SetFloat(const std::string& name, float value);

		private:
			uint32_t m_VertexShader;
			uint32_t m_FragmentShader;
			uint32_t m_ShaderProgramID;

			const char* m_VertexShaderCode;
			const char* m_FragmentShaderCode;

			std::string m_VertexCode;
			std::string m_FragmentCode;
	};
}