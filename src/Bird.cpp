#include <Globals.hpp>
#include <Bird.hpp>

Bird::Bird() : shape(20.f) {
    reset();
    shape.setFillColor(sf::Color(255, 255, 100));
}

void Bird::reset() {
    position = {WIDTH/2, HEIGHT/2};
    velocity = {HORIZONTAL_SPEED, JUMP_FORCE};
    shape.setPosition(position);
}

void Bird::jump() { velocity.y = JUMP_FORCE; }
void Bird::reverseX() { velocity.x = -velocity.x; }

void Bird::update() {
    velocity.y += GRAVITY;
    position += velocity;
    shape.setPosition(position);
}

void Bird::setPositionX(float x) {
    position.x = x;
    shape.setPosition(position);
}

const sf::Vector2f& Bird::getPosition() const { return position; }
const sf::CircleShape& Bird::getShape() const { return shape; }
sf::FloatRect Bird::getBounds() const { return shape.getGlobalBounds(); }
