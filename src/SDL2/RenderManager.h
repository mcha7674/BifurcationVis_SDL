#pragma once
#include <SDL.h>
#include <iostream>


class RenderManager
{
public:
	RenderManager(std::string winName, int winWidth, int winHeight);
	virtual ~RenderManager();
	void PrepScene();
	void Present();
	void DrawPointF(float x, float y);
	void SetRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
	inline static RenderManager& Get() { return *s_Instance; }

private:
	SDL_Window* m_window;
	SDL_Renderer *m_renderer;
	int m_windowFlags;
	// Singleton Instance
	static RenderManager* s_Instance;
};





