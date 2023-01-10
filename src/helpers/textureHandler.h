#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureHandler
{
private:
    const std::string ROOT_DIR;
    std::unordered_map<std::string, sf::Texture> nameToTextureMap;

    void load(const std::string &spriteName);
    bool isLoaded(const std::string &spriteName);

public:
    TextureHandler(const std::string rootDir);
    const sf::Texture &get(const std::string &spriteName);
};

#endif
