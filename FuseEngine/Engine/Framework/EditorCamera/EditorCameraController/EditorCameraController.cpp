#include "EditorCameraController.h"

Fuse::EditorCameraController::EditorCameraController() {}
Fuse::EditorCameraController::EditorCameraController(float left, float right, float bottom, float top)
{
	m_MovementDistance = 0.1f;
	m_MovementSpeed = 0.01f;

	m_TrackedKeys.emplace_back('W');
	m_TrackedKeys.emplace_back('A');
	m_TrackedKeys.emplace_back('S');
	m_TrackedKeys.emplace_back('D');

	m_Input = new Fuse::Input(m_TrackedKeys);
	m_EditorCamera = new Fuse::EditorCamera(left, right, bottom, top);
}
Fuse::EditorCameraController::~EditorCameraController() {}

void Fuse::EditorCameraController::Update()
{
	if (m_Input->GetKeyDown('W'))
	{
		m_EditorCamera->SetPosition(glm::vec3(m_EditorCamera->GetPosition().x, m_EditorCamera->GetPosition().y - m_MovementDistance * m_MovementSpeed, 0.0f));
	}
	else if (m_Input->GetKeyDown('S'))
	{
		m_EditorCamera->SetPosition(glm::vec3(m_EditorCamera->GetPosition().x, m_EditorCamera->GetPosition().y + m_MovementDistance * m_MovementSpeed, 0.0f));
	}
	else if (m_Input->GetKeyDown('A'))
	{
		m_EditorCamera->SetPosition(glm::vec3(m_EditorCamera->GetPosition().x - m_MovementDistance * m_MovementSpeed, m_EditorCamera->GetPosition().y, 0.0f));
	}
	else if (m_Input->GetKeyDown('D'))
	{
		m_EditorCamera->SetPosition(glm::vec3(m_EditorCamera->GetPosition().x + m_MovementDistance * m_MovementSpeed, m_EditorCamera->GetPosition().y, 0.0f));
	}
}