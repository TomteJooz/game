#include "world.h"
#include "helpers/constants.h"
#include "helpers/textureHandler.h"
#include "map/tileMap.h"

World::World() : components{}
{
    TileMap tilemap = TileMap{textureHandler.get("./tileset/midgroundTest.png")};
    tilemap.load(sf::Vector2u(16, 16), 16, 8);

    Entity player = Entity{textureHandler.get("./character/sprites/Idle.png"), sf::IntRect{81, 72, 33, 56}};
    player.setPosition({16 * 4, 8});

    add(std::make_shared<TileMap>(tilemap));
    add(std::make_shared<Entity>(player));
}

void World::tick(sf::Time delta)
{
    components.tick(delta);
}

void World::renderTo(sf::RenderWindow &window)
{
    window.draw(components);
}

void World::add(std::shared_ptr<IComponent> component)
{
    components.add(component);
}
