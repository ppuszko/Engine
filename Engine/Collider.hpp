#pragma once
#include <raylib.h>
#include <vector>
#include <memory>

#include "Component.hpp"

template <typename Derived, typename Shape>
class Collider : public Component
{
protected:
	int width_, height_;
	

public:
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

	virtual bool CheckCollision(Collider* collider)
	{
		static_cast<Derived*>(this)->CheckCollision(collider);
	}
};
template <typename Derived, typename Shape>
std::vector<Collider<Derived, Shape>*> Collider<Derived, Shape>::allColliders;