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
	inline double GetMouseWheelOffset() { return wheelOffset; }
	inline int GetMouseX() { return mousePosCoord.first; }
	inline int GetMouseY() { return mousePosCoord.second; }
	inline bool GetMousePressedState() { return mouseButtonPressed; }
	inline bool GetMouseReleasedState() { return mouseButtonReleased; }
	inline bool GetWheelMovedState() { return wheelMoved; }
private:
	SDL_Event m_event;
	// Mouse Variables
	std::pair<int, int> mousePosCoord;
	double wheelOffset;
	bool mouseButtonPressed;
	bool mouseButtonReleased;
	bool wheelMoved;

};

