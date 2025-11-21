#include "ImageRenderer.h"
#include "RenderManager.h"

#include <cassert>
#include <SDL3_image/SDL_Image.h>

ImageRenderer::ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize)
	: Renderer(transform, resourcePath)
{
	RM->GetTexture(resourcePath);

	_sourceRect = SDL_FRect
	{
		sourceOffset.x,
		sourceOffset.y,
		sourceSize.x,
		sourceSize.y
	};

	_destinationRect = SDL_FRect
	{
		transform->position.x,
		transform->position.y,
		transform->scale.x,
		transform->scale.y
	};
}

void ImageRenderer::Update(float dt)
{
	Vector2 offset = (Vector2(-_transform->size.x, -_transform->size.y) / 2.0f) * _transform->scale;

	_destinationRect.x = _transform->position.x + offset.x;
	_destinationRect.y = _transform->position.y + offset.y;

	_destinationRect.w = _transform->size.x * _transform->scale.x;
	_destinationRect.h = _transform->size.y * _transform->scale.y;
}

void ImageRenderer::Render()
{
	SDL_RenderTextureRotated(RM->GetRenderer(), RM->GetTexture(_resourcePath), &_sourceRect, &_destinationRect
		, _transform->rotation, NULL, SDL_FLIP_NONE);
}

void ImageRenderer::LoadTexture(std::string path, SDL_Renderer* renderer) // ... ????
{
	//_texture = IMG_LoadTexture(renderer, path.c_str());
	//assert(_texture);

	//_sourceRect = { 0.f, 0.f, (float)_texture->w,(float)_texture->h };

}