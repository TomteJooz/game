#include <iostream>
#include "textureHandler.h"

void TextureHandler::load(std::string const &spriteName)
{
    std::cout << "LOADING: " << spriteName << std::endl;
    sf::Texture texture;

    bool success{texture.loadFromFile(TextureHandler::ROOT_DIR + spriteName)};

    if (success)
    {
        nameToTextureMap[spriteName] = texture;
    }
    else
    {
        throw std::invalid_argument("Couldn't find image at: " + TextureHandler::ROOT_DIR + spriteName);
    }
}

TextureHandler::TextureHandler(const std::string ROOT_DIR) : ROOT_DIR{std::move(ROOT_DIR)}, nameToTextureMap{}
{
}

const sf::Texture &TextureHandler::get(std::string const &spriteName)
{
    if (!isLoaded(spriteName))
    {
        TextureHandler::load(spriteName);
    }
    return nameToTextureMap.at(spriteName);
}

bool TextureHandler::isLoaded(std::string const &spriteName)
{
    return nameToTextureMap.find(spriteName) != nameToTextureMap.end();
}
