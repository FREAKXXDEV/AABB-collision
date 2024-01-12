#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(sf::Vector2f position, sf::Vector2f size);
	~GameObject();

public:
	void draw(sf::RenderWindow& window);

public:
	sf::RectangleShape rect;
};