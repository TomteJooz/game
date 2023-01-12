#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include "components/components.h"
#include "helpers/textureHandler.h"

class World : public IInteractable
{
public:
    World();

private:
    TextureHandler textureHandler{"../assets/"};
};

#endif
