#include "GameObject.h"

#include <cassert>
#include <SDL3_image/SDL_image.h>
#include "Game.h"

GameObject::GameObject(std::string texturePath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, texturePath.c_str());
	assert(_texture); // si falla avisa

	_position = Vector2();
	_destinationRect = { _position.x, _position.y, 100.f, 100.f };
	_sourceRect = { _position.x, _position.y, (float)_texture->w, (float)_texture->h };
}

void GameObject::Render(SDL_Renderer* renderer)
{
	// copia la porcion de textura definida por sourceRect en el target de renderizado actual (destinationRect)
	SDL_RenderTexture(renderer, _texture, &_sourceRect, &_destinationRect); // source y destination se pasan por referencia para ahorrar memoria
}

void GameObject::SetPosition(Vector2 position)
{
	_position = position;
	_destinationRect.x = _position.x;
	_destinationRect.y = _position.y;
}
