#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird();
    void reset();
    void jump();
    void reverseX();
    void update();
    void setPositionX(float x);
    const sf::Vector2f& getPosition() const;
    const sf::CircleShape& getShape() const;
    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
};
