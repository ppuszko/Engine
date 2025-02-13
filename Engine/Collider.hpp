#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include <variant>



class Collider 
{
protected:
	int width_, height_;
	

public:
	using Shape = std::variant<float, Rectangle>;
	static std::vector<Collider*> allColliders;
	Shape shape;

	Collider()
	{
		allColliders.push_back(this);
	}

	virtual ~Collider()
	{
		allColliders.erase(std::remove(allColliders.begin(), allColliders.end(), this), allColliders.end());
	}

	virtual bool CheckCollision(Collider* collider) = 0;
	virtual void ShowCollider() = 0;
};

