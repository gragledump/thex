/******************************************************************************/
/*!
\file   Engine.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Implementation for the Engine class.
*/
/******************************************************************************/

#include "Engine.h"
#include "ScopeTimer.h"

#include "System.h"
#include "Debug.h"

#include "Message.h"
#include <cassert>

bool Engine::running_ = false;
std::vector<System*> Engine::system_;

/******************************************************************************/
/*!
  \brief
    Initialize the engine.
*/
/******************************************************************************/
void Engine::Init()
{
    // Instantiate & push_back systems
    Debug* debug_ = new Debug("test.log");
	System* debugSys = static_cast<System*>(debug_);

	system_.push_back(debugSys);

    running_ = true;

    StrMessage msg(MSG_STR, nullptr, "Engine Initialized & Running");
    msg.Send();
}

/******************************************************************************/
/*!
  \brief
    Updates the engine in a loop and times the duration of each tick

*/
/******************************************************************************/
void Engine::Game_Loop()
{
    float dt = 1.f / 60.f;

    while (running_)
    {
        // ScopeTimer begins timing when it is created and stops when it dies, stores duration in dt
        Time::ScopeTimer frameTimer(&dt);
        Update(dt);
    }
}

/******************************************************************************/
/*!
  \brief
    Stops the engine and frees associated memory
*/
/******************************************************************************/
void Engine::Shutdown()
{
    running_ = false;
}

/******************************************************************************/
/*!
  \brief
    Broadcasts messages to any listener with a HandleMessage()

  \param msg
    Message to be broadcast

*/
/******************************************************************************/
void Engine::Broadcast(const Message& msg)
{
	for (unsigned i = 0; i < system_.size(); i++)
	{
		system_[i]->HandleMessage(msg);
	}
}

/******************************************************************************/
/*!
  \brief
    Iterates through engine systems and updates

  \param dt
    Time since the last tick in seconds

*/
/******************************************************************************/
void Engine::Update(float dt)
{
    // Update systems
}