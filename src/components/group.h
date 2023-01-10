#ifndef GROUP_H
#define GROUP_H

#include <SFML/Graphics.hpp>

#include "components.h"

class IComponent;

class Group : public sf::Drawable
{
public:
    Group() : children{} {}

    void add(std::shared_ptr<IComponent> child);
    void remove(std::shared_ptr<IComponent> child);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void tick(sf::Time delta);

private:
    std::vector<std::shared_ptr<IComponent>> children;
};

#endif
