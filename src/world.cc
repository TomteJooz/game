#include "world.h"
#include "helpers/constants.h"
#include "helpers/textureHandler.h"
#include "map/tileMap.h"
#include "components/entities/testPlayer.h"

World::World() : IInteractable{}
{
    TileMap tilemap = TileMap{textureHandler.get("./tileset/midgroundTest.png")};
    tilemap.load(sf::Vector2u(16, 16), 16, 8);

    addChild(std::make_shared<TileMap>(tilemap));

    Texture tex = Texture{textureHandler.get("./character/sprites/Idle.png"), sf::IntRect{81, 72, 33, 56}};
    tex.setScale(3.f, 3.f);
    
    TestPlayer player = TestPlayer{tex, 350.f};

    addChild(std::make_shared<TestPlayer>(player));
}
