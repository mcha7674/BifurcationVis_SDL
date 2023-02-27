#pragma once
#include <SDL.h>
#include <iostream>


class RenderManager
{
public:
	RenderManager(SDL_Window* window);
	virtual ~RenderManager();
	void PrepScene();
	void Present();
	void DrawPointF(float x, float y);
	void SetRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

private:
	SDL_Renderer *m_renderer;
};





