#include "collidableObject.h"

CollidableObject::CollidableObject(sf::Vector2f size, sf::Vector2f position) {
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);

	body.setPosition(position);
}

CollidableObject::~CollidableObject() {}

void CollidableObject::draw(sf::RenderWindow &window) {
	window.draw(body);
}