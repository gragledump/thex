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

/******************************************************************************/
/*!
  \brief
	Constructor for base message.

  \param type
    Type of message used by handlers to determine course of action.

  \param sender
    Void pointer to entity which sent the message.

*/
/******************************************************************************/
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