#include "player.h"

Player::Player(sf::Vector2f position, float speed, std::vector<sf::RectangleShape> collidableObjects) {
	this->speed = speed;
	this->position = position;
	this->collidableObjects = collidableObjects;

	rect.setSize(sf::Vector2f(64.0f, 64.0f));
	rect.setOrigin(rect.getSize() / 2.0f);
	rect.setPosition(this->position);
	rect.setFillColor(sf::Color::White);

	direction = sf::Vector2f(0.0f, 0.0f);
}

Player::~Player() {}

void Player::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction.x = -1.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction.x = 1.0f;
	else direction.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction.y = -1.0f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction.y = 1.0f;
	else direction.y = 0.0f;
}

void Player::move(float deltaTime) {
	input();
	if (direction.x != 0.0f && direction.y != 0.0f) direction /= sqrt(2.0f);
	
	position.x += direction.x * speed * deltaTime;
	position.y += direction.y * speed * deltaTime;
	rect.setPosition(position);

	collisionResponse();
}

void Player::collisionResponse() {
	// thanks to Hilze Vonck
	for (auto rect : collidableObjects) {
		sf::Vector2f thisPosition = this->rect.getPosition();
		sf::Vector2f otherPosition = rect.getPosition();
		
		sf::Vector2f thisHalfSize = this->rect.getSize() / 2.0f;
		sf::Vector2f otherHalfSize = rect.getSize() / 2.0f;

		float deltaX = thisPosition.x - otherPosition.x; // negative means moving right | positive means moving left
		float deltaY = thisPosition.y - otherPosition.y; // negative means moving down | positive means moving up

		float overlapX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
		float overlapY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y); 

		if (overlapX < 0.0f && overlapY < 0.0f) { // means colliding
			if (overlapX > overlapY) { // checking which one has the least overlap (both are negative)
				if (deltaX > 0.0f)  // moving left
					position.x -= overlapX;
				else if (deltaX < 0.0f) // moving right
					position.x += overlapX;
				return;
			}

			// overlapY > overlapX
			if (deltaY > 0.0f) // moving up
				position.y -= overlapY;
			if (deltaY < 0.0f) // moving down
				position.y += overlapY;
		}
	}
}

void Player::draw(sf::RenderWindow &window) { 
	window.draw(rect); 
}

void Player::update(float deltaTime) {
	move(deltaTime);
}