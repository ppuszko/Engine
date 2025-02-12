#pragma once
#include <raylib.h>
#include <memory>
#include <typeindex>
#include <string>
#include <unordered_map>
#include <iostream>

#include "Component.hpp"
#include "SpriteRenderer.hpp"


class GameObject
{
private:
	std::unordered_map<std::type_index, std::unique_ptr<Component>> components_;


public:
	Vector2 position_;
	Vector2 scale_;
	std::string name_;
	
	GameObject(std::string name);
	~GameObject();

	template <typename T, typename... Args>

	void AddComponent(Args && ...args)
	{
		std::type_index type = typeid(T);
		std::unique_ptr<T> component = std::make_unique<T>(std::forward<Args>(args)...);
		component->owner = this;
		component->UponCreation();
		components_[type] = std::move(component);

	}
	void Update();
	void Clean();

};


