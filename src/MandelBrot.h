#pragma once
#include "SDL2/Layer.h"
#include "SDL2/App.h"
#include "SDL2/EventListener.h"
#include <complex>
#include <cmath>
#include <unordered_map>

class MandelBrot : public Layer
{
public:
	MandelBrot();
	virtual ~MandelBrot() = default;
	// Layer Functions
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	// Create Fractal
	void CreateFractal();
	// Render
	void RenderSet();
	// returns 0 is complex number c is in set, i otherwise.
	int IsInSet(std::complex<double> c);
	// maps screen coordinates to world coordinates (outputMin, outputMax)
	// Note, 'value' can x scr coordinate or y scr coordinate, or any other value
	// ... that we wish to map
	template<typename T>
	T Map(T value, T inputMin,
		T inputMax, T outputMin, T outputMax)
	{
		return ((value - inputMin) * (outputMax - outputMin)) /
			(inputMax - inputMin) + outputMin;
	}

private:
	EventListener eventListener;
	// Color of each Pixel on screen
	std::vector< std::vector<int>> pixelIters;
	// Render manager to render pixels
	std::shared_ptr<RenderManager> renderManager;
	// Number of recursive iterations for the set.
	int recursions;
	int currentIterations;
	// store color intensity
	int cIntensity;
	// Range of the mandelbrot set we will render (normale -2 to 2)
	std::pair<double, double> range;
	double zoomFactor;
	int pixelX;
	int pixelY;
	int scrWidth;
	int scrHeight;
};

