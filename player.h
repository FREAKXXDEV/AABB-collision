#pragma once
#include "gameObject.h"

class Player : public GameObject {
public:
	Player(sf::Vector2f position, sf::Vector2f size);
	void update(float deltaTime);
	void addCollisionObject(GameObject object) { collidableObjects.push_back(object); }

private:
	void getInput();
	void move(float deltaTime);

private:
	sf::Vector2f direction;
	sf::Vector2f velocity;
	float speed;

	std::vector<GameObject> collidableObjects;
};
