#include "player.h"

Player::Player(sf::Vector2f position, sf::Vector2f size)
	: GameObject(position, size)
	, velocity(0.0f, 0.0f)
	, direction(0.0f, 0.0f)
	, collidableObjects{} {
	
	speed = 600.0f;
}

void Player::update(float deltaTime) {
	move(deltaTime);
}

void Player::getInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction.x = -1.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x = 1.0f;
	else direction.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction.y = -1.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y = 1.0f;
	else direction.y = 0.0f;
}

void Player::move(float deltaTime) {
	getInput();

	if (direction.x != 0.0f && direction.y != 0.0f) 
		direction /= sqrt(2.0f);

	velocity = direction * speed * deltaTime;
	rect.move(velocity);
}
