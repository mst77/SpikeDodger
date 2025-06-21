#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <Game.hpp>

int main() {
    srand(time(nullptr));
    Game game;
    game.run();
    return 0;
}
