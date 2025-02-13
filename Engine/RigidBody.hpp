#pragma once

#include <raylib.h>

#include "Component.hpp"
#include "Collider.hpp"
#include "GameObject.hpp"

class RigidBody : public Component
{
public:
	RigidBody(float gravity);

	Vector2 velocity_;
	float gravity_;
	
	void Update() override;
	void UponCreation() override;


};