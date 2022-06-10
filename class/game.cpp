#include <iostream>
#include <memory>
#include <string.h>
#include "game.hpp"

game::game(char *level)
{
    if (strcmp(level, "easy") == 0) {
        _nbr_of_rows = 9;
        _nbr_of_columns = 9;
        _nbr_of_mines = 10;
    } else if (strcmp(level, "medium") == 0) {
        _nbr_of_rows = 16;
        _nbr_of_columns = 16;
        _nbr_of_mines = 40;
    } else if (strcmp(level, "hard") == 0) {
        _nbr_of_rows = 16;
        _nbr_of_columns = 30;
        _nbr_of_mines = 99;
    } else {
        std::cout << "Invalid level" << std::endl;
        exit(1);
    }
    _bomb_texture = std::make_unique<sf::Texture>();
    _bomb_texture->loadFromFile("asset/bomb.png");
    _bomb_sprite = std::make_shared<sf::Sprite>(*_bomb_texture);
    _window.create(sf::VideoMode(800, 600), "Minesweeper");
}

game::~game()
{
    // Nothing to do
}

std::shared_ptr<sf::Sprite> game::getSprite()
{
    return _bomb_sprite;
}

void game::createBomb()
{
    std::vector<sf::Vector2f> posed_bomb;
    for (int i = 0; i < _nbr_of_mines; i++) {
        int x = rand() % _nbr_of_columns;
        int y = rand() % _nbr_of_rows;
        if (std::find(posed_bomb.begin(), posed_bomb.end(), sf::Vector2f(x, y)) != posed_bomb.end()) {
            i--;
        } else {
            posed_bomb.push_back(sf::Vector2f(x, y));
            _bombs.push_back(bomb(_bomb_sprite, x, y));
        }
    }
}

void game::displayBombPosition()
{
    for (auto &bomb : this->_bombs) {
        std::cout << "Bomb position: " << bomb.getPosition().x << " " << bomb.getPosition().y << std::endl;
    }
    std::cout << "Patate" << std::endl;
}
