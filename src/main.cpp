#include <iostream>
#include <SFML/Graphics.hpp>

#include "helpers/constants.h"
#include "states/playState.h"
#include "states/stateMachine.h"

unsigned int windowWidth{16 * 16};
unsigned int windowHeight{16 * 8};

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window{sf::VideoMode(2560, 1920, desktop.bitsPerPixel), "Greatest game of all time"};

    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);

    StateMachine game{};
    game.run(window, std::make_shared<PlayState>());

    return 0;
}
