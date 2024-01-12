#pragma once
#include "gameObject.h"

class Player : public GameObject {
public:
	Player(sf::Vector2f position, sf::Vector2f size);
	~Player();

public:
	void update(float deltaTime);
	sf::Vector2f getPosition() { return rect.getPosition(); }
	void addCollisionObject(sf::RectangleShape collisionObject) { collidableObjects.push_back(collisionObject); }

private:
	void getInput();
	void move(float deltaTime);
	void collisionResponse();

private:
	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;

	std::vector<sf::RectangleShape> collidableObjects;
};