#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <SFML/Graphics.hpp>

#include "state.h"

class StateMachine
{
public:
    void run(sf::RenderWindow &window, std::shared_ptr<IState> state);
};

#endif
