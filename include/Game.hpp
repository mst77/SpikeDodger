#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <SpikeWall.hpp>
#include <Bird.hpp>

class Game {
public:
    Game();
    void run();

private:
    void handleInput();
    void update();
    void handleWallCollision();
    void checkCollisions();
    void reset();
    void render();

    sf::RenderWindow window;
    Bird bird;
    std::unique_ptr<SpikeWall> currentWall;
};
