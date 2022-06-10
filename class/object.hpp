#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class object {
    public:
        object(std::shared_ptr<sf::Sprite>, float x, float y);
        ~object();
        void display(sf::RenderWindow& window);
        sf::Vector2f getPosition();
    protected:
        std::shared_ptr<sf::Sprite> _sprite;
        sf::Vector2f _position;
};

class bomb : public object {
    public:
        bomb(std::shared_ptr<sf::Sprite> sprite, float x, float y);
        ~bomb();
};
