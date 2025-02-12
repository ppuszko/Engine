#include "Collider.hpp"
#include "Component.hpp"

class BoxCollider : Component, Collider
{
public: 
	bool CheckCollision(Collider* collider) override
	{

		if (typeid(collider) == typeid(BoxCollider))
		{
			//return CheckCollisionRecs(collider)
		}
		else
		
			
	}
};