#include "playState.h"

PlayState::PlayState() : world{}
{
}

std::shared_ptr<IState> PlayState::tick(sf::Time delta)
{
    world.tick(delta);
    return nullptr;
}

void PlayState::renderTo(sf::RenderWindow &window)
{
    window.draw(world);
}
