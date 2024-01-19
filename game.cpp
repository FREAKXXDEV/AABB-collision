#include "game.h"

Game::Game()
	: window(sf::VideoMode(840, 520), "AABB Collision", sf::Style::Close)
	, player(sf::Vector2f(420.0f, 260.0f), sf::Vector2f(54.0f, 54.0f))
	, collidableObjects{ GameObject(sf::Vector2f(500, 400), sf::Vector2f(150, 50))
	, GameObject(sf::Vector2f(100, 300), sf::Vector2f(80, 250))
	, GameObject(sf::Vector2f(600, 350), sf::Vector2f(50, 150)) }
{
	for (auto obj : collidableObjects)
		player.addCollisionObject(obj);
}

void Game::run() {
	sf::Clock clock;
	float deltaTime = 0.0f;

	while (window.isOpen()) {
		 deltaTime = clock.restart().asSeconds();

		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents() {
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Game::update(float deltaTime) {
	player.update(deltaTime);

	for (auto other : collidableObjects)
		player.getCollider().checkCollision(other.getCollider());
}

void Game::render() {
	window.clear();

	for (auto obj : collidableObjects)
		obj.draw(window);
	player.draw(window);

	window.display();
}