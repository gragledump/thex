/******************************************************************************/
/*!
\file   Message.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Interface for the engine's message system.
*/
/******************************************************************************/

#pragma once

class Engine;

enum MSGType
{
      // Mere Examples
    MSG_UNKNOWN = 0,
    MSG_DEBUG,
	MSG_UTEST,
    MSG_KEY_UP,
    MSG_KEY_DOWN,
    MSG_MOUSE_MOVED,
    MSG_COLLISION,
    MSG_OBJECT_DESTROYED
};

/******************************************************************************/
/*!
  \class Message
  \brief
    Base Message type. Derive specific message classes with unique payloads in
	associated system files.
*/
/******************************************************************************/
struct Message
{
	Message(MSGType type, void* sender);

	MSGType type_;
    void*   sender_;  // Void Ptr to sender will be recast by handler based on message type. Document thoroughly when you do this or you get linguine'd

    void Send();
private:
	Message() = delete;
};

// Example of a derived message class that might be written in an Input system
struct KeyMessage : public Message
{
    int mKeyCode_;
};
