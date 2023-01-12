#ifndef ENTITY_H
#define ENTITY_H

#include "components.h"

class Texture : public IRenderable, public sf::Transformable
{
public:
    virtual ~Texture() = default;
    explicit Texture(const sf::Texture &texture);
    Texture(const sf::Texture &texture, sf::IntRect rect);
    Texture(const sf::Texture &texture, sf::VertexArray vertices);

    virtual void handleMessage(Message &message) override;

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    const sf::Texture &texture;
    sf::VertexArray vertices;
};

#endif
