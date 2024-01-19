#pragma once
#include <SFML/Graphics.hpp>
#include "collider.h"

class GameObject {
public:
	GameObject(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow &window);
	Collider getCollider() { return Collider(rect); }

private:
	sf::RectangleShape rect;
};
