#pragma once
#include <SDL.h>
#include <iostream>
#include "Window.h"
#include "LayerStack.h"
#include <complex>
class App
{
public:
	App(std::string windowName, int winWidth, int winHeight, bool fullScreen);
	virtual ~App();
	void Run();
	void PushLayer(Layer* layer);
	inline LayerStack* GetLayerStack() { return &m_LayerStack; }

	inline static App& Get() { return *s_Instance; }

	inline SDL_Renderer* GetRenderer() { return renderer; }

	int IsInSet(std::complex<double> c);
private:
	std::unique_ptr<Window> m_window;
	SDL_Renderer* renderer;
	LayerStack m_LayerStack;

	bool isRunning;
	// Singleton Instance
	static App* s_Instance;
};