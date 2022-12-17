#include <SFML/Graphics.hpp>

#ifndef STATES_H
#define STATES_H

class State : public sf::Drawable
{
public:
    virtual ~State() = default;
    virtual State *update(sf::Time delta) = 0;
    virtual void handleInput(sf::Time delta) = 0;
};

class PlayState : public State
{
};
class MenuState : public State
{
};

#endif
