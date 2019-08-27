#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component {
private:
	PositionComponent* position;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.h = srcRect.w = 32;
		destRect.h = destRect.w = 64;
	}

	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void update() override {
		destRect.x = position->x();
		destRect.y = position->y();
	}
};