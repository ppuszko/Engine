#include <typeindex>


#include "Collider.hpp"
#include "GameObject.hpp"
#include "CircleCollider.hpp"

class BoxCollider : public Collider<BoxCollider, Rectangle>
{
public: 
		
	bool CheckCollision(Collider* collider) 
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
		shape.width = 32, shape.height = 32;
		shape.x = owner->position_.x - shape.width / 2;
		shape.y = owner->position_.y - shape.height;
	}
	

private:
	bool CheckWithRec(BoxCollider* collider)
	{
		return CheckCollisionRecs(this->shape, collider->shape);
	}
	bool CheckWithCircle(CircleCollider* collider)
	{
		return CheckCollisionCircleRec(collider->owner->position_, collider->shape, this->shape);
	}
};