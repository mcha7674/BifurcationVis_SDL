#include "RenderManager.h"

RenderManager* RenderManager::s_Instance = nullptr;

RenderManager::RenderManager(std::string winName, int winWidth, int winHeight)
{
	s_Instance = this;
	m_windowFlags = SDL_WINDOW_SHOWN;
	// Init_EVERYTHING flag will initialize ALL of SDL (Video, Audio, timer, etc)
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";


		// Window Creation
		m_window = SDL_CreateWindow(winName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, m_windowFlags);
		if (m_window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(m_window, 100, 100);
		}
		else {
			std::cout << "FAILED TO OPEN" << std::endl;
		}
	}
	/*Renderer Creation, needs window, driver specification(-1 means use the first one that
		satisfies everything we need), and finally the last place is for any renderer flags.
		RendererFlags can include things like SDL_RENDER_ACCELERATED which tells sdl to use the graphics card
		instead of the cpu for rendering.
		*/
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer) {
		SDL_SetRenderDrawColor(m_renderer, 121, 121, 121, 255);
		std::cout << "Renderer created!\n";
		SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
	}
	else {
		std::cout << "Failed to create Renderer!" << std::endl;
	}

}

RenderManager::~RenderManager() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
}

void RenderManager::PrepScene()
{
	// Prepare the Scene
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}

void RenderManager::Present()
{
	SDL_RenderPresent(m_renderer);
	SDL_Delay(0);
}

void RenderManager::DrawPointF(float x, float y)
{
	SDL_RenderDrawPointF(m_renderer, x, y);
}

void RenderManager::SetRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}


