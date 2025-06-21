#include <SFML/Graphics.hpp>

class SpikeWall {
public:
    SpikeWall(bool isLeft);
    void generate();
    void draw(sf::RenderWindow& window) const;
    bool checkCollision(const sf::FloatRect& bounds) const;

private:
    sf::ConvexShape createSpike(float y) const;

    bool isLeftWall;
    std::vector<sf::ConvexShape> spikes;
};
