#include "gameObject.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size) {
	rect.setSize(size);
	rect.setOrigin(size / 2.0f);
	rect.setPosition(position);
}

void GameObject::draw(sf::RenderWindow &window) {
	window.draw(rect);
}
