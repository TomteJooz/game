#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "../messages/messageSystem.h"

class IComponent : public sf::Drawable, public IMessageHandler, public std::enable_shared_from_this<IComponent>
{
public:
    virtual ~IComponent() = default;
    IComponent(std::shared_ptr<IComponent> parent = nullptr) : _parent{parent}, _children{} {}

    auto begin() { return _children.begin(); }
    auto end() { return _children.end(); }
    auto cbegin() const { return _children.begin(); }
    auto cend() const { return _children.end(); }
    auto begin() const { return _children.begin(); }
    auto end() const { return _children.end(); }

    void addChild(std::shared_ptr<IComponent> child);
    void remove(std::shared_ptr<IComponent> child);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void tick(sf::Time delta);

    void bindParent(std::shared_ptr<IComponent> parent);

protected:
    void handleMessage(Message &message) override;
    void sendMessage(Message &message) override;
    bool isMessageForMe(Message &message) override;
    void redirectMessage(Message &message) override;

    std::shared_ptr<IComponent> _parent;
    std::vector<std::shared_ptr<IComponent>> _children;
};

class IRenderable : public IComponent
{
public:
    virtual ~IRenderable() = default;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

private:
    void tick(sf::Time delta) override{};
};

class IUpdatable : public IComponent
{
public:
    virtual ~IUpdatable() = default;
    virtual void tick(sf::Time delta) = 0;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override{};
};

class IInteractable : public IComponent
{
public:
    virtual ~IInteractable() = default;
};

#endif
