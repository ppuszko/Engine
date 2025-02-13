#include "RigidBody.hpp"


RigidBody::RigidBody(float gravity)
{
	velocity_ = { 5,5 };
	gravity_ = gravity;
}
void RigidBody::Update()
{
	Vector2 lastPosition = owner->position_;
	Vector2 newPosition = { owner->position_.x + velocity_.x * GetFrameTime(), owner->position_.y + velocity_.y * GetFrameTime() };
	owner->position_ = newPosition;
	auto collider = owner->GetCollider();
	for (const auto& col : Collider::allColliders)
	{
		if (collider->CheckCollision(col))
		{
			owner->position_ = lastPosition;
			break;
		}
		
	}
	collider->ShowCollider();
}

void RigidBody::UponCreation()
{
}
