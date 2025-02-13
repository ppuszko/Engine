#include "GameObject.hpp"

GameObject::GameObject(std::string name) : name_(name), position_({ 300, 200 }), scale_({ 1, 1 }) 
{
}

GameObject::~GameObject()
{
	std::cout << "GameObject deleted\n";
}

Collider* GameObject::GetCollider()
{
	auto it = components_.find(colliderType_);
	return (it == components_.end() ? nullptr : dynamic_cast<Collider*>(it->second.get()));
}


void GameObject::Update()
{
	for (const auto& [key, value] : components_)
	{
		value->Update();
	}
}

void GameObject::Clean()
{
	
}


