#include <SDL3/SDL.h>
#include <exception>
#include "Game.h"


int main() 
{
	Game game;
	try {
		game.Init();
	}
	catch (std::exception& e) {
		game.Release();
		return -1;
	}

	while (game.IsRunning())
	{
		// Gestión del Input
		game.HandleEvents();

		// UPDATE - Actualizar lógica (objetos, etc.)
		game.Update();

		// Renderizar
		game.Render();
	}
	game.Release();
	return 0;
}

