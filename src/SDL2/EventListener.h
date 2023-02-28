#pragma once
#include <SDL.h>
#include <iostream>
class EventListener
{
public:
	EventListener();
	~EventListener() = default;
	bool Listen();
	

	// Getters
	inline int GetMouseX() { return mousePosCoord.first; }
	inline int GetMouseY() { return mousePosCoord.second; }
	inline bool GetMousePressedState() { return mouseButtonPressed; }
	inline bool GetMouseReleasedState() { return mouseButtonReleased; }
private:
	SDL_Event m_event;
	// Mouse Variables
	std::pair<int, int> mousePosCoord;
	bool mouseButtonPressed;
	bool mouseButtonReleased;

};

