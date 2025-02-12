#include "SpriteRenderer.hpp"
#include "GameObject.hpp"
#include <stdexcept>

SpriteRenderer::SpriteRenderer(Sprite* sprite)
{
	if (sprite == nullptr) throw std::runtime_error("Sprite* is null. Failed to initialize sprite renderer");

	SwapSprite(sprite);


	sourceRect = { (float)spriteWidth_ * animFrameX, (float)spriteHeight_ * animFrameY, (float)spriteWidth_, (float)spriteHeight_ };
	//destinationRect = { owner->position_.x, owner->position_.y, spriteWidth_ * owner->scale_.x, spriteHeight_ * owner->scale_.y };
	
}

SpriteRenderer::~SpriteRenderer()
{
	std::cout << "Renderer deleted\n";
}

void SpriteRenderer::RenderAnimation()
{
	//if(managedTexture_ == nullptr) throw std::runtime_error("Sprite* is null. Failed to initialize sprite renderer");
	DrawTexturePro(*managedTexture_, sourceRect, destinationRect, spriteOrigin_, 0, WHITE);
	ManageFrames();
}

void SpriteRenderer::ManageFrames()
{
	animFrameX++;
	if (animFrameX > spriteCols_)
	{
		animFrameX = 0;
		animFrameY++;
	}
	if (animFrameY > spriteRows_) animFrameY = 0;

	sourceRect = { (float)spriteWidth_ * animFrameX, (float)spriteHeight_ * animFrameY, (float)spriteWidth_, (float)spriteHeight_ };
}

void SpriteRenderer::SwapSprite(Sprite* sprite)
{
	managedTexture_ = sprite->GetTexture();
	animFrameX = 0, animFrameY = 0;
	spriteWidth_ = sprite->width_, spriteHeight_ = sprite->height_;
	spriteRows_ = sprite->rows_, spriteCols_ = sprite->cols_;
	spriteOrigin_ = sprite->origin_;
}

void SpriteRenderer::Update()
{
	RenderAnimation();
}

void SpriteRenderer::UponCreation()
{
	destinationRect = { owner->position_.x, owner->position_.y, spriteWidth_ * owner->scale_.x, spriteHeight_ * owner->scale_.y };
}
