#pragma once
#include <SDL.h>
#include <iostream>
#include "LayerStack.h"
#include "RenderManager.h"

class App : public RenderManager
{
public:
	App(std::string windowName, int winWidth, int winHeight);
	virtual ~App();
	void Run();
	void PushLayer(Layer* layer);
	inline LayerStack* GetLayerStack() { return &m_LayerStack; }

	inline static App& Get() { return *s_Instance; }

	inline int GetWinWidth() { return m_Width; }
	inline int GetWinHeight() { return m_Height; }

private:
	LayerStack m_LayerStack;
	int m_Width;
	int m_Height;
	std::string m_winName;
	bool isRunning;
	// Singleton Instance
	static App* s_Instance;
};