/******************************************************************************/
/*!
\file   System.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Interface for the main engine systems.
*/
/******************************************************************************/

#pragma once

struct Message;

/******************************************************************************/
/*!
  \class System
  \brief
    Interface for engine systems.
*/
/******************************************************************************/
class System
{
public:
	virtual ~System() {}
	virtual void Tick(float dt) = 0;                     // Function to be called each tick
	virtual void HandleMessage(const Message& msg) = 0;  // Message Handler
};
