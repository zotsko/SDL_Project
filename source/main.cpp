#include "Game.h"
#include "RenderManager.h"
#include "TimeManager.h"

#include <SDL3/SDL.h>
#include <exception>
#include <iostream>

int main()
{
	Game game;


	try
	{
		game.Init();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what();
		game.Release();
		return -1;
	}

	while (game.IsRunning())
	{
		TIME.Update();
		//std::cout << TIME.GetDeltaTime() << std::endl;
		if (TIME.ShouldUpdateGame()) {
			// frame
			game.HandleEvents();
			game.Update();
			game.Render();

			// frame time reset
			TIME.ResetDeltaTime();
		}
		
	}

	game.Release();

	return 0;
}