#include "entity.h"

Entity::Entity(const sf::Texture &texture) : Entity{texture, sf::IntRect{0, 0, static_cast<int>(texture.getSize().x), static_cast<int>(texture.getSize().y)}}
{
}

Entity::Entity(const sf::Texture &texture, sf::IntRect rect) : texture{texture}, vertices{sf::Quads, 4}
{
    vertices[0].position = sf::Vector2f(0.f, 0.f);
    vertices[1].position = sf::Vector2f(rect.width, 0.f);
    vertices[2].position = sf::Vector2f(rect.width, rect.height);
    vertices[3].position = sf::Vector2f(0.f, rect.height);

    vertices[0].texCoords = sf::Vector2f(rect.left, rect.top);
    vertices[1].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
    vertices[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
    vertices[3].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
}

Entity::Entity(const sf::Texture &texture, sf::VertexArray vertices) : texture{texture}, vertices{vertices}
{
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(vertices, states);
}
