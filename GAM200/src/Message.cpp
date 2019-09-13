/******************************************************************************/
/*!
\file   Message.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Implementation for the engine's message system.
*/
/******************************************************************************/

#include "Message.h"
#include "Engine.h"

Message::Message() : type_(MSG_UNKNOWN), sender_(nullptr)
{}

Message::Message(MSGType type, void* sender) : type_(type), sender_(sender)
{}

/******************************************************************************/
/*!
  \brief
    Signals the engine to broadcast the message.

*/
/******************************************************************************/
void Message::Send()
{
    Engine::Broadcast(*this);
}