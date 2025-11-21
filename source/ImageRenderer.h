#pragma once
#include "Renderer.h"
#include "Vector2.h"

class ImageRenderer : public Renderer
{
public:
	ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize);

	virtual void Update(float dt) override;

	void Render() override;


	void LoadTexture(std::string path, SDL_Renderer* renderer) override;

};