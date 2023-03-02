#include "MandelBrot.h"


MandelBrot::MandelBrot()
	:Layer("MandelBrot Layer")
{
	renderManager = std::make_shared<RenderManager>(App::Get().GetWindow());
	// number of recursions of the z = z^2 + c equation
	// The higher the number of recursions the "deeper" the zoom that you can theoretically do
	recursions = 100;
	currentIterations = 0;
	// MandelBrot ranges from c = -2 to c = +2
	range = { -2.0, 2.0 };
	zoomFactor = 1.0;
	// color Intensity
	cIntensity = 0;
	// Initialize pixel tracking variables
	pixelX = 0;
	pixelY = 0;
	// Initialize screen dimension variables
	scrWidth = App::Get().GetWinWidth();
	scrHeight = App::Get().GetWinHeight();
	// Initialize pixel color grid
	pixelIters = std::vector<std::vector<int>>(scrWidth,std::vector<int>(scrHeight, 0));
}

void MandelBrot::OnAttach()
{
	
}
void MandelBrot::OnDetach() {}

void MandelBrot::OnUpdate()
{
	renderManager->PrepScene();

	if (eventListener.Listen()) { App::Get().Quit(); }

	// Fill Array with fractal data
	CreateFractal();
	RenderSet();

	renderManager->Present();
}

void MandelBrot::RenderSet()
{
	for (pixelX = 0; pixelX < scrWidth; pixelX++)
	{
		for (pixelY = 0; pixelY < scrHeight; pixelY++)
		{
			if (pixelIters[pixelX][pixelY] == 0) continue; // don't draw pixels in the set (keep them black - the background color)
			cIntensity = Map<int>(pixelIters[pixelX][pixelY], 0, recursions, 0, 255);
			renderManager->SetRenderColor(3*cIntensity, 2 * cIntensity, 5 * cIntensity);
			// Draw Colored point
			renderManager->DrawPoint(pixelX, pixelY);
		}
	}
	
}

void MandelBrot::CreateFractal()
{
	for (pixelX = 0; pixelX < scrWidth; pixelX++)
	{
		for (pixelY = 0; pixelY < scrHeight; pixelY++)
		{
			// map the screen pixel to a pixel on the MandelBrot Set range
			currentIterations = IsInSet(std::complex<double>
				(
				Map<double>(pixelX, 0, (double)scrWidth, range.first, range.second), 
				Map<double>(pixelY, 0, (double)scrHeight, range.first, range.second)
				)
			);
			// if a divergent coordinate, then draw colored point
			// If is in set, we don't render a point and leave the dark background
			if (currentIterations != 0)
			{
				// Update color based on number of recursion iterations!!
				pixelIters[pixelX][pixelY] = currentIterations;
			}
		}
	}
}

int MandelBrot::IsInSet(std::complex<double> c)
{
	// start z off at 0
	std::complex<double> z(0, 0);
	for (int i = 0; i < recursions; i++)
	{
		// recurse the z function a 'resolution' number of times
		z = z * z + c;
		/*
			If the norm is greater than some number (like 10),
			then the choice of "c" causes z to DIVERGe and is thus not in the set
		*/ 
		if (std::norm(z) > 10) { return i; }
	}
	// if 0 is returned, value for c is in the set
	return 0;
}

