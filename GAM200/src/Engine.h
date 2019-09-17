/******************************************************************************/
/*!
\file   Engine.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Interface for the Engine class.
*/
/******************************************************************************/

#pragma once

struct Message;
class System;

/******************************************************************************/
/*!
  \class Engine
  \brief
	Static class that drives engine systems
*/
/******************************************************************************/
class Engine
{
public:

	static void Init();

	static void Game_Loop();

	static void Shutdown();

	static void Broadcast(const Message& msg);

private:

	static void Update(float dt);

	static bool running_;

	static std::vector<System*> system_;
};
