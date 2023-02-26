#pragma once
#include "SDL2/Layer.h"
#include "SDL2/App.h"
#include <complex>
#include <numeric>
#include <cmath>

#define RENDERER App::Get().GetRenderer()

class MandelBrot : public Layer
{
public:
	MandelBrot();
	virtual ~MandelBrot() = default;
	// Layer Functions
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;

	int IsInSet(std::complex<double> c);

private:
	
};

