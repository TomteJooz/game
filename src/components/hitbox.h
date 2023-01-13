#ifndef HITBOX_H
#define HITBOX_H

#include "components.h"

class Hitbox : public IUpdatable, public sf::Transformable
{
public:
    virtual ~Hitbox() = default;
    explicit Hitbox(sf::FloatRect rect);

    void tick(sf::Time delta) override;
    sf::FloatRect getRect();

private:
    sf::FloatRect _rect;
};

#endif
