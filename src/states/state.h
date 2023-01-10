#include <SFML/Graphics.hpp>

#ifndef STATES_H
#define STATES_H

#include <memory>

class IState : public std::enable_shared_from_this<IState>
{
public:
    virtual ~IState() = default;

    virtual std::shared_ptr<IState> tick(sf::Time delta) = 0;
    virtual void renderTo(sf::RenderWindow &window) = 0;

    virtual void onKeyPress(sf::Time delta, sf::Keyboard::Key keycode) {};
    virtual void onKeyRelease(sf::Time delta, sf::Keyboard::Key keycode) {};
};

class ExitState : public IState
{
public:
    std::shared_ptr<IState> tick(sf::Time) { return nullptr; }
    void render(sf::RenderWindow &) {}
};

#endif
