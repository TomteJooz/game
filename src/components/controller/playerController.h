#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "controller.h"

class PlayerController : public IController
{
public:
    PlayerController(std::shared_ptr<IComponent> parent, float speed) : IController{parent, speed} {}
    void tick(sf::Time delta) override;

private:
    sf::Vector2f getDirection() override;
};

#endif
