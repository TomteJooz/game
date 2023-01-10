#ifndef ENTITY_H
#define ENTITY_H

#include "../components.h"

class Entity : public IInteractable, public sf::Transformable
{
public:
    explicit Entity(const sf::Texture &texture);
    Entity(const sf::Texture &texture, sf::IntRect rect);
    Entity(const sf::Texture &texture, sf::VertexArray vertices);
    
    virtual void tick(sf::Time delta) override{};

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    const sf::Texture &texture;
    sf::VertexArray vertices;
};

#endif
