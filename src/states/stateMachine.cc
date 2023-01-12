#include <iostream>

#include "stateMachine.h"

void StateMachine::run(sf::RenderWindow &window, std::shared_ptr<IState> state)
{
    sf::Clock fpsClock{};
    unsigned int frameCount = 0;

    sf::Clock eventClock{};
    sf::Clock tickClock{};

    sf::Time eventTime{};
    sf::Time tickTime{};

    while (state)
    {
        sf::Event event{};
        eventTime = eventClock.restart();

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                return;
            case sf::Event::KeyPressed:
                state->onKeyPress(eventTime, event.key.code);
                break;
            case sf::Event::KeyReleased:
                state->onKeyRelease(eventTime, event.key.code);
                break;
            default:
                break;
            }
        }

        window.clear(sf::Color{150, 150, 255});
        
        tickTime = tickClock.restart();

        if (std::shared_ptr<IState> newState = state->tick(tickTime))
        {
            if (std::dynamic_pointer_cast<ExitState>(newState))
            {
                return;
            }
            else
            {
                state = newState;
            }
            continue;
        }

        state->renderTo(window);

        window.display();

        frameCount++; // increment the frame count

        if (fpsClock.getElapsedTime().asSeconds() > 1.0)
        {
            float fps = frameCount / fpsClock.getElapsedTime().asSeconds();
            std::cout << "FPS: " << fps << std::endl;
            frameCount = 0;
            fpsClock.restart();
        }
    }
}
