#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "../components.h"

/*
 * Stuff to add:
 * Hitbox
 * Refrence to map?
 */

class IController : public IUpdatable
{
public:
    ~IController() = default;
    IController(std::shared_ptr<IComponent> parent, float speed);

protected:
    virtual void move(sf::Time delta);
    virtual sf::Vector2f getDirection() = 0;

    float _speed;
};

#endif
