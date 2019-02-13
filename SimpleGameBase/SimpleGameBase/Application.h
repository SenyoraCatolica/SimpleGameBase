#pragma once

#include "Globals.h"
#include "SimpleTimer.h"
#include <list>

class Module;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

	void CloseApp();
	void LogGui(const char* log) const;

	void SetAppName(const char* title);
	const char* GetAppName() const;
	void SetOrganizationName(const char* title);
	const char* GetOrganizationName() const;

	void SetCapFrames(bool capFrames);
	bool GetCapFrames() const;
	void SetMaxFramerate(uint maxFramerate);
	uint GetMaxFramerate() const;

private:

	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();

public:


private:

	std::string			m_name;
	std::string			m_organization;
	bool				m_closeApp = false;

	//timer
	SimpleTimer	m_msTimer;
	SimpleTimer m_lastFrameSecTime;
	int m_fps = 60;
	int m_msCapped = -1;
	int m_frameCount = 0;
	int m_lastFrameSecCount = 0;
	uint32_t m_lastFrameMs = 0;
	int m_maxFramerate = 60;
	double dt;

	std::list<Module*>	m_listModules;
};

extern Application* App;