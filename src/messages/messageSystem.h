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
    std::string Content;
};

class IMessageHandler
{
public:
    Tag getTag() { return tag; };
    virtual void handle(Message message) = 0;
    virtual void sendMessageTo(Message message, Tag Recipient) = 0;

protected:
    Tag tag;
};

#endif
