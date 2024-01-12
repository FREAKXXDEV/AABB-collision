#include "gameObject.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size) {
	this->rect.setSize(size);
	this->rect.setOrigin(size / 2.0f);
	this->rect.setPosition(position);
}

GameObject::~GameObject() {}

void GameObject::draw(sf::RenderWindow & window) {
	window.draw(rect);
}
