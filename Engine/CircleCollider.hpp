#pragma once

#include "Collider.hpp"
#include "Component.hpp"


class CircleCollider : public Collider, public Component
{
	CircleCollider()
	{
		shape = 0.f;
	}

	bool CheckCollision(Collider* collider) override
	{
		return true;
	}
};
