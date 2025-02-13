#pragma once
#include <typeindex>

#include "Collider.hpp"
#include "Component.hpp"

#include "CircleCollider.hpp"



class BoxCollider : public Collider, public Component
{
public: 
	BoxCollider()
	{
		shape = Rectangle{ 0, 0, 0, 0 };
	}
		
	bool CheckCollision(Collider* collider) override
	{
		if (collider != this && collider!=nullptr)
		{
			std::type_index type = typeid(*collider);
			if (type == typeid(BoxCollider))
			{
				BoxCollider* col = dynamic_cast<BoxCollider*>(collider);
				return CheckWithRec(col);
			}
			else if (type == typeid(CircleCollider))
			{
				CircleCollider* col = dynamic_cast<CircleCollider*>(collider);
				return CheckWithCircle(col);
			}
		}
		return false;	
	}

	void UponCreation() override
	{
		if (Rectangle* rect = std::get_if<Rectangle>(&shape))
		{
			if (owner != nullptr)
			{
				rect->width = 64, rect->height = 64;
				rect->x = owner->position_.x - rect->width / 2;
				rect->y = owner->position_.y - rect->height / 2;
			}
			
		}
		Resize(50, 50);
		
	}
	
	void ShowCollider() override
	{
		const Rectangle* rect1 = std::get_if<Rectangle>(&shape);
		DrawRectangleLines(rect1->x, rect1->y, rect1->width, rect1->height, RED);
	}

	void Update() override
	{
		if (Rectangle* rect = std::get_if<Rectangle>(&shape))
		{
			if (owner != nullptr)
			{
				rect->x = owner->position_.x - rect->width / 2;
				rect->y = owner->position_.y - rect->height / 2;
			}

		}
	}

	void Resize(int width, int height)
	{
		Rectangle* rect1 = std::get_if<Rectangle>(&shape);
		rect1->width = width;
		rect1->height = height;

	}

private:
	bool CheckWithRec(BoxCollider* collider)
	{
		const Rectangle* rect1 = std::get_if<Rectangle>(&shape);
		const Rectangle* rect2 = std::get_if<Rectangle>(&collider->shape);
		return CheckCollisionRecs(*rect1, *rect2);
	}
	bool CheckWithCircle(CircleCollider* collider)
	{
		const Rectangle* rect = std::get_if<Rectangle>(&shape);
		const float* radius = std::get_if<float>(&collider->shape);
		return CheckCollisionCircleRec(collider->owner->position_, *radius, *rect);
	}
};