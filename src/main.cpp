#include <iostream>
#include "SDL2/App.h"
#include "MandelBrot.h"


class MandelBrotApp : public App
{
public:
	MandelBrotApp() 
		:App("The MandelBrot Set", 800, 800)
	{
		PushLayer(new MandelBrot());
	}
};


// With SDL, the main function must include the parameters.
int main(int arg, char* args[]) {

	std::unique_ptr<MandelBrotApp> app = std::make_unique<MandelBrotApp>();
	app->Run();

	return 0;
}

