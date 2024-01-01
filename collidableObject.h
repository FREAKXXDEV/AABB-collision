#include <SFML\Graphics.hpp>

class CollidableObject {
public:
	CollidableObject(sf::Vector2f size, sf::Vector2f position);
	~CollidableObject();

	void draw(sf::RenderWindow &window);
	sf::RectangleShape getBody() { return body; }

private:
	sf::RectangleShape body;
};