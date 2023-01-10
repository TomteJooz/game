#ifndef TileMap_H
#define TILE_MAP_H
#define TILE_MAP_H

#include "../components/entities/entity.h"

class TileMap : public Entity
{
public:
    TileMap(const sf::Texture &texture);
    void load(sf::Vector2u tileSize, unsigned int width, unsigned int height);
};

#endif
