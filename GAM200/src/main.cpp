/******************************************************************************/
/*!
\file   Main.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Creates the engine abstraction & runs the main loop.

*/
/******************************************************************************/

#include "Engine.h"

/******************************************************************************/
/*!

  \brief
    I'm beginning to feel like a Rap God, Rap God, All my people from the front
    to the back nod, back nod, Now who thinks their arms are long enough to slap
    box, slap box? They said I rap like a robot, so call me Rap-bot

  \param argc

  \param argv

*/
/******************************************************************************/
int main(int argc, char* argv[])
{
	Engine::Init();

	Engine::Game_Loop();

    Engine::Shutdown();

	return 0;
}