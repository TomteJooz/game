#include "testPlayer.h"
#include "../texture.h"
#include "../controller/playerController.h"

TestPlayer::TestPlayer(Texture texture, float speed)
{
    addChild(std::make_shared<Texture>(texture));
    addChild(std::make_shared<PlayerController>(PlayerController{std::make_shared<TestPlayer>(*this), speed}));
}
