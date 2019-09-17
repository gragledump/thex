/******************************************************************************/
/*!
\file   Component.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Base component class for implementing entity-component architecture.
*/
/******************************************************************************/

#pragma once

struct Message;

/******************************************************************************/
/*!
  \class Component
  \brief
    Interface for components.
*/
/******************************************************************************/
class Component
{
public:
	virtual ~Component() {}
	virtual void Tick(float dt) = 0;                      // Function to be called each tick
	virtual void Handle_Message(const Message& msg) = 0;  // Message Handler
};
