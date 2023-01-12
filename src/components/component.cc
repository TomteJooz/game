#include "components.h"

void IComponent::addChild(std::shared_ptr<IComponent> child)
{
    _children.push_back(child);
}

void IComponent::remove(std::shared_ptr<IComponent> child)
{
    _children.erase(std::find(_children.begin(), _children.end(), child));
}

void IComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto child : _children)
    {
        if (child)
            child->draw(target, states);
    }
}

void IComponent::tick(sf::Time delta)
{
    for (auto child : _children)
    {
        if (child)
            child->tick(delta);
    }
}

void IComponent::bindParent(std::shared_ptr<IComponent> parent)
{
    _parent = parent;
}

void IComponent::handleMessage(Message &message)
{
    if (!isMessageForMe(message))
    {
        redirectMessage(message);
        return;
    }
}

void IComponent::sendMessage(Message &message)
{
    switch (message.Recipient)
    {
    case Tag::PARENT:
        if (_parent)
            _parent->handleMessage(message);
        break;

    case Tag::SIBLINGS:
        if (_parent)
            _parent->handleMessage(message);

    case Tag::CHILDREN:
        for (auto child : _children)
        {
            if (child)
                child->handleMessage(message);
        }
        break;

    case Tag::ALL:
        message.Recipient = Tag::PARENT;
        sendMessage(message);

        message.Recipient = Tag::CHILDREN;
        sendMessage(message);

        message.Recipient = Tag::SIBLINGS;
        sendMessage(message);

    default:
        break;
    }
}

bool IComponent::isMessageForMe(Message &message)
{
    switch (message.Recipient)
    {
    case Tag::SIBLINGS:
        if (message.Sender == Tag::CHILD)
        {
            return false;
        }

    default:
        break;
    }

    return true;
}

void IComponent::redirectMessage(Message &message)
{
    switch (message.Recipient)
    {
    case Tag::SIBLINGS:
        if (message.Sender == Tag::CHILD)
        {
            message.Recipient = Tag::CHILDREN;
            sendMessage(message);
        }

    default:
        break;
    }
}
