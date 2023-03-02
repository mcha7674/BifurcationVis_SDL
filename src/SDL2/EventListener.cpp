#include "EventListener.h"


EventListener::EventListener()
{
	mousePosCoord = { 0,0 };
	mouseButtonPressed = false;
	mouseButtonReleased = false;
	wheelOffset = 0;
	wheelMoved = false;
}

bool EventListener::Listen()
{ 
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type) {

		case SDL_MOUSEMOTION:
			mousePosCoord.first = m_event.motion.x;
			mousePosCoord.second = m_event.motion.y;
			/*mouseButtonPressed = false;
			mouseButtonReleased = false;*/
			break;
		case SDL_MOUSEBUTTONDOWN:
			mousePosCoord.first = m_event.button.x;
			mousePosCoord.second = m_event.button.y;
			mouseButtonPressed = true;
			mouseButtonReleased = false;
			break;
		case SDL_MOUSEBUTTONUP:
			mousePosCoord.first = m_event.button.x;
			mousePosCoord.second = m_event.button.y;
			mouseButtonReleased = true;
			mouseButtonPressed = false;
			break;
		case SDL_MOUSEWHEEL:
			wheelOffset += m_event.wheel.preciseY;
			break;
		case SDL_QUIT:
			return true;
		default:
			wheelOffset = 0;
			break;
		}
		
	}
	return false;
}


