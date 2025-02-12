#pragma once
#include <raylib.h>
#include <vector>
#include <memory>


class Collider
{
protected:
	int width_, height_;
	

public:
	static std::vector<Collider*> allColliders;

	Collider()
	{
		allColliders.push_back(this);
	}

	virtual ~Collider()
	{
		allColliders.erase(std::remove(allColliders.begin(), allColliders.end(), this), allColliders.end());
	}

	virtual bool CheckCollision(Collider* collider) = 0;
};

std::vector<Collider*> Collider::allColliders;