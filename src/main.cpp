#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    game game_obj(av[1]);
    game_obj.createBomb();
    while (game_obj._window.isOpen()) {
        sf::Event event;
        while (game_obj._window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game_obj._window.close();
        }
        game_obj._window.display();
    }
}
