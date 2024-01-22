#pragma once
#include <SFML/Graphics.hpp>
#include "collider.h"

class Player {
public:
	Player(sf::Vector2f position, sf::Vector2f size);
	void update(float deltaTime);
	void draw(sf::RenderWindow &window);

	Collider getCollider() { return Collider(rect); }

private:
	void getInput();
	void move(float deltaTime);

private:
	sf::RectangleShape rect;

	sf::Vector2f direction;
	sf::Vector2f velocity;
	const float speed;
};
