#include <SFML/Graphics.hpp>
#include <iostream>
#include "object.hpp"

object::object(std::shared_ptr<sf::Sprite> sprite, float x, float y) {
    _sprite = sprite;
    _position = {x, y};
}

object::~object()
{
    // Nothing to do here.
}

void object::display(sf::RenderWindow& window)
{
    _sprite->setPosition(_position);
    window.draw(*_sprite);
}

sf::Vector2f object::getPosition()
{
    return _position;
}

bomb::bomb(std::shared_ptr<sf::Sprite> sprite, float x, float y) : object(sprite, x, y)
{
    // Nothing to do here.
}

bomb::~bomb()
{
    // Nothing to do here.
}
