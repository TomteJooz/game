#ifndef TileMap_H
#define TILE_MAP_H
#define TILE_MAP_H

#include "../components/texture.h"

class TileMap : public Texture
{
public:
    TileMap(const sf::Texture &texture);
    void load(sf::Vector2u tileSize, unsigned int width, unsigned int height);
};

#endif
