#pragma once

#include "Sprite.hpp"
#include "Component.hpp"

class SpriteRenderer : public Component
{
private:
	Texture2D* managedTexture_ = nullptr;
	int animFrameX, animFrameY;
	int spriteWidth_, spriteHeight_;
	Vector2 spriteOrigin_;
	int spriteCols_, spriteRows_;
	Rectangle destinationRect;
	Rectangle sourceRect;
	float animationSpeed = 1;
	float timeElapsed = 0;

public:
	SpriteRenderer(Sprite* sprite);
	~SpriteRenderer() override;
	//void RenderSprite();
	void RenderAnimation();
	void ManageFrames();
	void SwapSprite(Sprite* sprite);
	void ChangeAnimSpeed(float speedRatio);
	void Update() override;
	void UponCreation() override;

};