#include "controller.h"

IController::IController(std::shared_ptr<IComponent> parent, float speed) : _speed{speed}
{
    bindParent(parent);
}

void IController::move(sf::Time delta)
{
    sf::Vector2f dir = getDirection();
    dir *= (_speed * delta.asMicroseconds() / 1000000.0f);
    
    MoveMessage message{};
    message.Offset = dir;
    message.Type = MessageType::MOVE;
    message.Sender = Tag::CHILD;
    message.Recipient = Tag::SIBLINGS;

    sendMessage(message);
}
