#include <SFML/Graphics.hpp>
#include "player.h"
#include "collidableObject.h"

static const float VIEW_WIDTH = 800.0f;
static const float VIEW_HEIGHT = 600.0f;


int main() {
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Player Control", sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));

	CollidableObject obstacle1(sf::Vector2f(200, 50), sf::Vector2f(120, 400));
	CollidableObject obstacle2(sf::Vector2f(80, 200), sf::Vector2f(550, 300));


	std::vector<sf::RectangleShape> collidableObjects{ obstacle1.getBody(), obstacle2.getBody() };

	// Player
	Player player(sf::Vector2f(400.0f, 300.0f), 400.0f, collidableObjects);	

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

		player.update(deltaTime);
		// view.setCenter(window.getSize().x / 2.0f, window.getSize().y / 2.0f); // static camera
		view.setCenter(player.getPosition()); // dynamic camera

		window.clear();
		window.setView(view);

		player.draw(window);
		obstacle1.draw(window);
		obstacle2.draw(window);

		window.display();
	}

	return 0;
}