#include "GameObject.hpp"

GameObject::GameObject(std::string name) : name_(name), position_({ 300, 200 }), scale_({ 1, 1 }) 
{
}

GameObject::~GameObject()
{
	std::cout << "GameObject deleted\n";
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


