#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "state.h"
#include "../world.h"

class PlayState : public IState
{
public:
    PlayState();
    
    std::shared_ptr<IState> tick(sf::Time delta) override;
    void renderTo(sf::RenderWindow &window) override;

private:
    World world;
};

#endif
