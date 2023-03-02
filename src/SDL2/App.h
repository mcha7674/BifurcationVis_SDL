#pragma once
#include <SDL.h>
#include <iostream>
#include "LayerStack.h"
#include "RenderManager.h"

class App 
{
public:
	App(std::string windowName, int winWidth, int winHeight);
	virtual ~App();
	void Run();
	void PushLayer(Layer* layer);
	inline LayerStack* GetLayerStack() { return &m_LayerStack; }

	inline static App& Get() { return *s_Instance; }

	inline SDL_Window* GetWindow() { return m_window; }

	inline int GetWinWidth() { return m_Width; }
	inline int GetWinHeight() { return m_Height; }
	inline void Quit() { isRunning = false; }

private:
	SDL_Window* m_window;
	LayerStack m_LayerStack;
	int m_Width;
	int m_Height;
	int m_windowFlags;
	std::string m_winName;
	bool isRunning;
	// Singleton Instance
	static App* s_Instance;
};