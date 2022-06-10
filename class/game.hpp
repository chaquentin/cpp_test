#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "object.hpp"

class game {
    public:
        sf::RenderWindow _window;
        game(char *level);
        ~game();
        void createBomb();
        void displayBombPosition();
        std::shared_ptr<sf::Sprite> getSprite();
    private:
        std::unique_ptr<sf::Texture> _bomb_texture;
        std::shared_ptr<sf::Sprite> _bomb_sprite;
        std::vector<bomb> _bombs;
        int _nbr_of_rows;
        int _nbr_of_columns;
        int _nbr_of_mines;
};
