#include <math.h>

#include "playerController.h"

void PlayerController::tick(sf::Time delta)
{
    IController::move(delta);
}

sf::Vector2f PlayerController::getDirection()
{
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    float len = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    if (len > 0.0f)
        return direction * (1.0f / len);
    else
        return direction;
}
