#include <SDL3/SDL.h>
#include <exception>

int main() 
{
	bool _isRunning;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

	try {
		if (!SDL_Init(SDL_INIT_VIDEO))
			throw SDL_GetError();

		if (!SDL_CreateWindowAndRenderer("Test", 512, 512, SDL_WINDOW_RESIZABLE, &_window, &_renderer))
			throw SDL_GetError();

		SDL_SetRenderDrawColor(_renderer, 225, 0, 0, 0xFF); // 0xFF = 255 en hexadecimal

		_isRunning = true;
	}
	catch (std::exception& e) {
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
		return -1;
	}

	while (_isRunning)
	{
		// Gestión del Input
		SDL_Event event;

		while (SDL_PollEvent(&event))
			if (event.type == SDL_EVENT_QUIT)
				_isRunning = false;

		// Actualizar lógica (objetos, etc.)


		// Renderizar
		SDL_RenderClear(_renderer);

		// ... ( renderizar objectos )
		SDL_RenderPresent(_renderer);

	}
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();

	return 0;
}