#ifndef TEST_PLAYER
#define TEST_PLAYER

#include "../components.h"
#include "../texture.h"

class TestPlayer : public IInteractable
{
public:
    TestPlayer(Texture texture, float speed);
};

#endif
