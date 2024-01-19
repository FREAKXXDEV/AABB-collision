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
	onCollision();
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

void Player::onCollision() {
	for (auto obj : collidableObjects) {
		sf::Vector2f thisPosition = rect.getPosition();
		sf::Vector2f thisHalfSize = rect.getSize() / 2.0f;

		sf::Vector2f objPosition = obj.rect.getPosition();
		sf::Vector2f objHalfSize = obj.rect.getSize() / 2.0f;

		float deltaX = objPosition.x - thisPosition.x;
		float deltaY = objPosition.y - thisPosition.y;

		float overlapX = abs(deltaX) - (thisHalfSize.x + objHalfSize.x);
		float overlapY = abs(deltaY) - (thisHalfSize.y + objHalfSize.y);

		if (overlapX < 0.0f && overlapY < 0.0f) {
			if (overlapX > overlapY) {
				if (deltaX < 0.0f) rect.move(-overlapX, 0.0f);
				else rect.move(overlapX, 0.0f);
				return;
			}

			if (deltaY < 0.0f) rect.move(0.0f, -overlapY);
			else rect.move(0.0f, overlapY);
			return;
		}
	}
}
