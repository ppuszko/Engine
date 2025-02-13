#pragma once

#include <memory>



class GameObject;

class Component
{
public:
	GameObject* owner;

	virtual ~Component() = default;
	virtual void Update() = 0;
	virtual void UponCreation() = 0;
};