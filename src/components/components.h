#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "group.h"

class Group;

class IComponent : public sf::Drawable, public std::enable_shared_from_this<IComponent>
{
public:
    IComponent() : children{} {}
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
    virtual void tick(sf::Time delta) = 0;

protected:
    Group *children;
};

class IRenderable : public IComponent
{
private:
    void tick(sf::Time delta) override{};

public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};

class IUpdatable : public IComponent
{
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override{};

public:
    virtual void tick(sf::Time delta) = 0;
};

class IInteractable : public IComponent
{
public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
    virtual void tick(sf::Time delta) = 0;
};

#endif
