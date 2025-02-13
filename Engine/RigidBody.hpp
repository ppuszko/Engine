#pragma once

#include <raylib.h>

#include "Component.hpp"
#include "Collider.hpp"

class RigidBody : public Component
{
public:
	Vector2 velocity;
	float gravity;
	
};