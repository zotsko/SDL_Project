#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"

#include <cassert>

Game::~Game()
{
}

void Game::Init()
{
	RM->Init();
	//SDL_SetRenderDrawColor(RM->GetRenderer(), 254, 0, 0, 0xFF);

	RM->LoadTexture("resources/cigarro.png");

	SDL_SetRenderDrawColor(_renderer, 225, 0, 0, 0xFF); // 0xFF = 255 en hexadecimal

	// Cargar todas las escenas
	assert(SM.AddScene("Gameplay", new Gameplay()));

	assert(SM.InitFirstScene("Gameplay"));

	_isRunning = true;
}
void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}
void Game::Update()
{
	SM.UpdateCurrentScene();
}
void Game::Render()
{
	RM->ClearScreen();
	
	SM.GetCurrentScene()->Render();

	RM->RenderScreen();
}

void Game::Release()
{
	RM->Release();
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw SDL_GetError();
}

/*void Game::CreateWindowAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer(
		"Test",
		RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE,
		&_window,
		&_renderer
	))
		throw SDL_GetError();
}*/