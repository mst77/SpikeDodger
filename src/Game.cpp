#include <Globals.hpp>
#include <Game.hpp>

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Spike Bounce") {
    window.setFramerateLimit(60);
    reset();
}

void Game::run() {
    while(window.isOpen()) {
        handleInput();
        update();
        render();
    }
}

void Game::handleInput() {
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) window.close();
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            bird.jump();
        }
    }
}

void Game::update() {
    bird.update();
    handleWallCollision();
    checkCollisions();
}

void Game::handleWallCollision() {
    auto pos = bird.getPosition();
    
    if (pos.x < 20) {
        currentWall = std::make_unique<SpikeWall>(false); // Spikes on right
        bird.reverseX();
        bird.setPositionX(20); // Move to just inside left wall
    } else if (pos.x > WIDTH - 20) {
        currentWall = std::make_unique<SpikeWall>(true); // Spikes on left
        bird.reverseX();
        bird.setPositionX(WIDTH - 20); // Move to just inside right wall
    }
}

void Game::checkCollisions() {
    if(bird.getPosition().y + 20 > HEIGHT || bird.getPosition().y + 20 < 0 ||
       currentWall->checkCollision(bird.getBounds())) {
        reset();
    }
}

void Game::reset() {
    bird.reset();
    currentWall = std::make_unique<SpikeWall>(false);
}

void Game::render() {
    window.clear(sf::Color(30, 30, 30));
    currentWall->draw(window);
    window.draw(bird.getShape());
    window.display();
}
