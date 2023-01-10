#ifndef MESSAGE_SYSTEM_H
#define MESSAGE_SYSTEM_H

#include "../helpers/tags.h"
#include "types.h"

template <typename T>
struct Context
{
    Type Type;
    T Data;
};

template <typename T>
struct Message
{
    Tag Sender;
    Tag Recipient;
    Context<T> Context;
};

class ISubject
{
    template <typename T>
    void sendMessageTo(Message<T> message, Tag Recipient);
};

class IObserver
{
    template <typename T>
    void handle(Message<T> message);
};

#endif
