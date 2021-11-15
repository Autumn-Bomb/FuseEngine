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
			void LinkShaders(const char* vertex, const char* fragment);
			void CreateShaders();
			void Use();

		public:
			void CheckShaderCompilation(GLuint shader);
			void CheckShaderLink(GLuint shaderProgram);

		public:
			void SetBool(const std::string& name, bool value);
			void SetInt(const std::string& name, int value);
			void SetFloat(const std::string& name, float value);

		private:
			uint32_t m_VertexShader;
			uint32_t m_FragmentShader;

			const char* m_VertexShaderCode;
			const char* m_FragmentShaderCode;

			uint32_t m_ShaderProgramID;
	};
}