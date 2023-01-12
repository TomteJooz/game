#ifndef MESSAGE_SYSTEM_H
#define MESSAGE_SYSTEM_H

#include <string>

#include "tags.h"
#include "messageTypes.h"

struct Message
{
    Tag Sender;
    Tag Recipient;
    MessageType Type;
    std::shared_ptr<Message> Answer;
};

struct MoveMessage : public Message
{
    sf::Vector2f Offset;
};

class IMessageHandler
{
public:
    virtual ~IMessageHandler() = default;

    virtual void handleMessage(Message &message) = 0;
    virtual void sendMessage(Message &message) = 0;
    virtual bool isMessageForMe(Message &message) = 0;
    virtual void redirectMessage(Message &message) = 0;

    Tag getTag() { return tag; };

protected:
    Tag tag;
};

#endif
