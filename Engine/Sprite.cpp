#include "Sprite.hpp"
#include <iostream>

Sprite::Sprite(std::string path, bool isMultiple)
{
	texture_ = LoadTexture(path.c_str());
	isMultiple_ = isMultiple;
	width_ = texture_.width;
	height_ = texture_.height;
	origin_ = { width_ / 2.f, (float)height_ };
}

Sprite::~Sprite()
{
	std::cout << "Sprite deleted\n";
	UnloadTexture(texture_);
}

void Sprite::ClipSpriteSheet(int cols, int rows)
{
	if (!isMultiple_) return;

	width_ /= cols;
	height_ /= rows;
	origin_ = { width_ / 2.f, height_ / 2.f };
}

Texture2D* Sprite::GetTexture() 
{
	return &texture_;
}


