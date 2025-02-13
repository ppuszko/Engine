#pragma once

#include "Collider.hpp"

class CircleCollider : public Collider<CircleCollider, float>
{
	bool CheckCollision(Collider* collider)
	{
		return true;
	}
};
