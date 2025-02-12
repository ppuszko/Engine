#pragma once

#include <raylib.h>
#include <string>

#include "Component.hpp"

class Sprite
{
private:
	bool isMultiple_;
	Texture2D texture_;

public:
	Sprite(std::string path, bool isMultiple = true);
	Sprite(const Sprite&) = delete;
	Sprite& operator=(const Sprite&) = delete;
	Sprite(Sprite&&) = delete;
	Sprite& operator=(Sprite&&) = delete;

	~Sprite();
	

	void ClipSpriteSheet(int cols, int rows);
	Texture2D* GetTexture();


	int width_, height_;
	Vector2 origin_;
	int cols_ = 1, rows_ = 1;
};