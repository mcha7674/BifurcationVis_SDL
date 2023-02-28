#include "MandelBrot.h"


MandelBrot::MandelBrot()
	:Layer("MandelBrot Layer")
{
	renderManager = std::make_shared<RenderManager>(App::Get().GetWindow());
	isLoading = true;
	// number of recursions (affects resolution)
	resolution = 100;
	// MandelBrot ranges from c = -2 to c = +2
	range = { -2.0, 2.0 };
}

void MandelBrot::OnAttach()
{

}
void MandelBrot::OnDetach() {}


void MandelBrot::OnUpdate()
{
	renderManager->PrepScene();

	for (double x = 0.0; x < 1.0; x += 0.001)
	{
		for (double y = 0.0; y < 1.0; y += 0.001)
		{
			double pointX = std::lerp(range.first, range.second, x);
			double pointY = std::lerp(range.first, range.second, y);
			// X is real part and Y is Imaginary part of the complex c in the equation z=z^2+c
			int iters = IsInSet(std::complex<double>(pointX, pointY));
			// Is in set - make black
			if (iters == 0)
			{
				renderManager->SetRenderColor(0, 0, 0);
			}
			else { // if a divergent coordinate, then Color these points
				renderManager->SetRenderColor(
					3 * iters % 255, 
					2 * iters % 255,
					5 * iters % 255);
			}
			renderManager->DrawPointF( x * App::Get().GetWinWidth(), y * App::Get().GetWinHeight());
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
	for (int i = 0; i < resolution; i++)
	{
		// recurse the z function a 'resolution' number of times
		z = z * z + c;
		// if the norm is greater than some number,
		// then z is DIVERGING and is not in the set
		if (std::norm(z) > 20) { return i; }
	}
	// if 0 is returned, value for c is in the set
	return 0;
}