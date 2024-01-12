#include <SFML/Graphics.hpp>
#include "constants.h"
#include "gameObject.h"
#include "player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Player Collision", sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

#pragma region Game Objects
	GameObject collidable1(sf::Vector2f(500, 400), sf::Vector2f(150, 50));
	GameObject collidable2(sf::Vector2f(100, 300), sf::Vector2f(80, 250));

	Player player(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f), sf::Vector2f(64.0f, 64.0f));

	player.addCollisionObject(collidable1.rect);
	player.addCollisionObject(collidable2.rect);
#pragma endregion

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

#pragma region Updates
		player.update(deltaTime);
		view.setCenter(player.getPosition());

		window.clear();
		window.setView(view);
#pragma endregion

#pragma region Visuals Updates
		collidable1.draw(window);
		collidable2.draw(window);
		player.draw(window);

		window.display();
#pragma endregion

	}
	return 0;
}