#include "playState.h"

PlayState::PlayState() : world{}
{
}

std::shared_ptr<IState> PlayState::tick(sf::Time delta)
{
    return nullptr;
}

void PlayState::renderTo(sf::RenderWindow& window)
{
    world.renderTo(window);
}
