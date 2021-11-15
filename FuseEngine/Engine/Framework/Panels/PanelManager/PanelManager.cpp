#include "PanelManager.h"

FuseEngine::PanelManager::PanelManager() {}
FuseEngine::PanelManager::~PanelManager() {}

void FuseEngine::PanelManager::AddPanel(const char* name, FuseEngine::BasePanel* panel)
{
	m_Panels[name] = panel; 
}

void FuseEngine::PanelManager::CreatePanels()
{
	AddPanel("Stats", &m_Stats);
	AddPanel("Scene View", &m_SceneView);
}

void FuseEngine::PanelManager::RenderActivePanels()
{
	for (auto panel : m_Panels)
	{
		if (panel.second->GetActiveState())
		{
			panel.second->OnImGuiRender();
		}
	}
}