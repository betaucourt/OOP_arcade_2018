#include "src/games/solarfox/Solarfox.hpp"
#include "src/lib/sfml/Sfml.hpp"
#include "src/Input.hpp"
#include "src/Error.hpp"

// g++ -Wall -Wextra -W -std=c++11 main2.cpp src/games/solarfox/Solarfox.cpp src/games/solarfox/Vessel.cpp src/lib/sfml/Sfml.cpp src/lib/sfml/Sound.cpp src/games/Entity.cpp src/games/IGame.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system


int main() {
    AGame *game = new Solarfox();
    IGraph *lib = new Sfml();

    lib->openWindow();
    while(1) {
        Input input = lib->getInput();
        game->compute(input);
        try {
            lib->displaySprite(game->getEntities());
        }
        catch (Error &e) {
            std::cout << e.what() << '\n';
            return 84;
        }
    }
    return 0;
}
