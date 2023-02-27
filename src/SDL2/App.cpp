#include "App.h"

App* App::s_Instance = nullptr;

App::App(std::string winName, int winWidth, int winHeight)
	:m_winName(winName), m_Width(winWidth), m_Height(winHeight), RenderManager(winName, winWidth, winHeight)
{
	s_Instance = this;
	isRunning = true;
	//renderManager = std::make_shared<RenderManager>(winName, winWidth, winHeight);
		
}

App::~App()
{
	
	SDL_Quit();
}

void App::Run()
{

	while (isRunning) {
		//handles any events that SDL noticed
		//the only event we'll check is the  SDL_QUIT event.
		SDL_Event event;

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
		// Run Each Layer's Update Function
		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

	}
}


void App::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}