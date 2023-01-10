#include "tileMap.h"

TileMap::TileMap(const sf::Texture &texture) : Entity{texture}
{
}

void TileMap::load(sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
    // define the level with an array of tile indices
    const int TILES[] =
    {
        10, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
        17, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 7, 8, 9,
        17, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 14, 15, 16,
        17, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 7, 8, 14, 15, 16,
        17, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 14, 15, 14, 15, 16,
        14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16,
        21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23,
        28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30,
    };

    // resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = TILES[i + j * width];

            // find its position in the tileset texture
            int column = tileNumber % (texture.getSize().x / tileSize.x);
            int row = tileNumber / (texture.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex *quad = &vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(column * tileSize.x, row * tileSize.y);
            quad[1].texCoords = sf::Vector2f((column + 1) * tileSize.x, row * tileSize.y);
            quad[2].texCoords = sf::Vector2f((column + 1) * tileSize.x, (row + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(column * tileSize.x, (row + 1) * tileSize.y);
        }
    }
}
