#include "Input.h"

std::vector<Fuse::Input*> Fuse::Input::m_Instances;

Fuse::Input::Input(std::vector<int> keysToTrack) : m_IsEnabled(true)
{
	for (int key : keysToTrack)
	{
		m_Keys[key] = false;
	}

	m_Instances.emplace_back(this);
}

Fuse::Input::~Input()
{
	m_Instances.erase(std::remove(m_Instances.begin(), m_Instances.end(), this), m_Instances.end());
}

void Fuse::Input::InitialiseCallback(GLFWwindow* window)
{
	glfwSetKeyCallback(window, Input::Callback);
}

bool Fuse::Input::GetKeyDown(int key)
{
	bool result = false;

	if (m_IsEnabled)
	{
		std::map<int, bool>::iterator it = m_Keys.find(key);

		if (it != m_Keys.end())
		{
			result = m_Keys[key];
		}
	}
	return result;
}

void Fuse::Input::SetKeyDown(int key, bool status)
{
	std::map<int, bool>::iterator it = m_Keys.find(key);
	
	if (it != m_Keys.end())
	{
		m_Keys[key] = status;
		std::cout << "Key: " << std::to_string(key).c_str() << " has been set to: " << std::to_string(status).c_str() << std::endl;
	}
}

void Fuse::Input::Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	for (Fuse::Input* input : m_Instances)
	{
		input->SetKeyDown(key, action != GLFW_RELEASE);
	}
}