#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Vector2f position, float speed, std::vector<sf::RectangleShape> collidableObjects);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow &window);

	sf::Vector2f getPosition() { return rect.getPosition(); };

private:
	void input();
	void move(float deltaTime);
	void collisionResponse();

private:
	sf::RectangleShape rect;

	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;
	
	std::vector<sf::RectangleShape> collidableObjects;
};