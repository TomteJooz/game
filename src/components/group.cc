#include "group.h"

void Group::add(std::shared_ptr<IComponent> child)
{
    children.push_back(child);
}

void Group::remove(std::shared_ptr<IComponent> child)
{
    children.erase(std::find(children.begin(), children.end(), child));
}

void Group::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto child : children)
    {
        child->draw(target, states);
    }
}

void Group::tick(sf::Time delta)
{
    for (auto child : children)
    {
        child->tick(delta);
    }
}
