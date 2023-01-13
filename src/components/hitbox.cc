#include <iostream>

#include "hitbox.h"

Hitbox::Hitbox(sf::FloatRect rect) : _rect{rect}
{
}

void Hitbox::tick(sf::Time delta)
{
    std::cout << "hitbox should handle move msg and check for collision if moved" << std::endl;
}

sf::FloatRect Hitbox::getRect()
{
    return _rect;
}
