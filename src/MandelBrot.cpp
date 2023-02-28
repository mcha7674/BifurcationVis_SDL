#include "MandelBrot.h"


MandelBrot::MandelBrot()
	:Layer("MandelBrot Layer")
{
	renderManager = std::make_shared<RenderManager>(App::Get().GetWindow());
	isLoading = true;
	// number of recursions of the z = z^2 + c equation
	recursions = 100;
	// MandelBrot ranges from c = -2 to c = +2
	range = { -2.0, 1.5 };
	// color Intensity
	cIntensity = 0;
}

void MandelBrot::OnAttach()
{
	
}
void MandelBrot::OnDetach() {}


void MandelBrot::OnUpdate(EventListener & eventListener)
{
	int scrWidth = App::Get().GetWinWidth();
	int scrHeight = App::Get().GetWinHeight();
	renderManager->PrepScene();

	for (int x = 0; x < scrWidth; x++)
	{
		// Start Listening to Events
		if (eventListener.Listen()) { App::Get().Quit(); break; }

		if (eventListener.GetMousePressedState()) {
			std::cout << "MOUSE DOWN AT: " << eventListener.GetMouseX() << ", "
				<< eventListener.GetMouseY() << std::endl;

		}
		if (eventListener.GetMouseReleasedState()) {
			std::cout << "MOUSE UP AT: " << eventListener.GetMouseX() << ", "
				<< eventListener.GetMouseY() << std::endl;
		}

		for (int y = 0; y < scrHeight; y++)
		{
			
			double pointX = Map<double>(x, 0, (double)scrWidth, range.first, range.second);
			double pointY = Map<double>(y, 0, (double)scrHeight, range.first, range.second);
			// X is real part and Y is Imaginary part of the complex c in the equation z=z^2+c
			int iters = IsInSet(std::complex<double>(pointX, pointY));
			// if a divergent coordinate, then draw colored point
			// If is in set, we don't render a point and leave the dark background
			if (iters != 0)
			{
				// Update color based on number of recursion iterations!!
				cIntensity = Map<int>(iters, 0 , recursions, 0, 255);
				renderManager->SetRenderColor(cIntensity * 2, cIntensity*2, cIntensity*5);
				// Draw Colored point
				renderManager->DrawPoint(x, y);
			}
		}
		if (isLoading) {
			renderManager->Present();
		}
		
		

	}
	isLoading = false;
	renderManager->Present();
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

