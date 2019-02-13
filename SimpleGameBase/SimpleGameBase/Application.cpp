#include "Application.h"
#include "Module.h"


Application::Application()
{

}

Application::~Application()
{
	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		delete *item;
}

bool Application::Init()
{
	bool ret = true;

	CONSOLE_LOG("Application Initialization --------------");
	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		ret = (*item)->Init();

	CONSOLE_LOG("Application Start --------------");
	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		ret = (*item)->Start();

	m_msCapped = 1000 / m_fps;

	m_msTimer.Start();
	m_lastFrameSecTime.Start();

	return ret;
}

void Application::PrepareUpdate()
{
	m_frameCount++;
	dt = (double)m_msTimer.ReadMs / 1000.0f;
	m_msTimer.Start();
}

void Application::FinishUpdate()
{
	if (m_lastFrameSecTime.ReadMs() > 1000)
	{
		m_lastFrameSecTime.Start();
		m_lastFrameSecCount = m_frameCount;
		m_frameCount = 0;
	}

	m_lastFrameMs = m_msTimer.ReadMs();
	if (m_msCapped > 0 && m_lastFrameMs < m_msCapped)
	{
		SDL_Delay(m_msCapped - m_lastFrameMs);
	}
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;
	PrepareUpdate();

	std::list<Module*>::iterator i = m_listModules.begin();

	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		ret = (*item)->PreUpdate();

	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		ret = (*item)->Update();

	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		ret = (*item)->PostUpdate();

	FinishUpdate();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = false;

	for (std::list<Module*>::const_reverse_iterator item = m_listModules.rbegin(); item != m_listModules.rend(); ++item)
		ret = (*item)->CleanUp();

	return ret;
}

void Application::AddModule(Module* mod)
{
	m_listModules.push_back(mod);
}

void Application::CloseApp()
{
	m_closeApp = true;
}

void Application::SetAppName(const char* title)
{
	m_name = title;
}

const char* Application::GetAppName() const
{
	return m_name.c_str();
}

void Application::SetOrganizationName(const char* title)
{
	m_organization = title;
}

const char* Application::GetOrganizationName() const
{
	return m_organization.c_str();
}

void Application::SetCapFrames(bool capFrames)
{
	m_msCapped = capFrames;
}

bool Application::GetCapFrames() const
{
	return m_msCapped;
}

void Application::SetMaxFramerate(uint maxFramerate)
{
	m_maxFramerate = maxFramerate;
}

uint Application::GetMaxFramerate() const
{
	return m_maxFramerate;
}