#include "player.h"

Player::Player(sf::Vector2f position, sf::Vector2f size) : GameObject(position, size) {
	this->position = position;
	direction = sf::Vector2f(0.0f, 0.0f);
	speed = 600.06;

	this->collidableObjects = std::vector<sf::RectangleShape>{};
}

Player::~Player() {}

void Player::getInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction.x = -1.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x = 1.0f;
	else direction.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction.y = -1.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y = 1.0f;
	else direction.y = 0.0f;

	if (direction.x != 0.0f && direction.y != 0.0f) direction /= sqrt(2.0f);
}

void Player::move(float deltaTime) {
	position.x += direction.x * speed * deltaTime;
	position.y += direction.y * speed * deltaTime;

	rect.setPosition(position);
}

void Player::collisionResponse() {
	for (sf::RectangleShape object : collidableObjects) {
		sf::Vector2f thisPosition = this->rect.getPosition();
		sf::Vector2f thisHalfSize = this->rect.getSize() / 2.0f;

		sf::Vector2f otherPosition = object.getPosition();
		sf::Vector2f otherHalfSize = object.getSize() / 2.0f;

		float deltaX = otherPosition.x - thisPosition.x;
		float deltaY = otherPosition.y - thisPosition.y;

		float overlapX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
		float overlapY = abs(deltaY) - (thisHalfSize.x + otherHalfSize.y);

		if (overlapX < 0.0f && overlapY < 0.0f) {
			if (overlapX > overlapY) {
				if (deltaX < 0.0f) position.x -= overlapX;
				else position.x += overlapX;
				return;
			}

			if (deltaY < 0.0f) position.y -= overlapY;
			else position.y += overlapY;
			return;
		}
	}
}

void Player::update(float deltaTime) {
	getInput();
	move(deltaTime);
	collisionResponse();
}