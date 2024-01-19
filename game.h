#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include "player.h"

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(float deltaTime);
	void render();

private:
	sf::RenderWindow window;
	Player player;
	std::vector<GameObject> collidableObjects;
};