#pragma once
#include "SDL2/Layer.h"
#include "SDL2/App.h"
#include "SDL2/EventListener.h"
#include <complex>
#include <cmath>

class MandelBrot : public Layer
{
public:
	MandelBrot();
	virtual ~MandelBrot() = default;
	// Layer Functions
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(EventListener& eventListener) override;
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
	std::shared_ptr<RenderManager> renderManager;
	int recursions;
	int cIntensity;
	bool isLoading;
	std::pair<double, double> range;
};

