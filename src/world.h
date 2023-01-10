#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "components/components.h"
#include "helpers/textureHandler.h"

class World
{
public:
    World();

    void tick(sf::Time delta);
    void renderTo(sf::RenderWindow &window);
    void add(std::shared_ptr<IComponent> component);

private:
    TextureHandler textureHandler{"../assets/"};
    Group components;
};

#endif
