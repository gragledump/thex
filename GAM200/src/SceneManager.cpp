/******************************************************************************/
/*!
\file   SceneManager.cpp
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/12/19
\brief
  System for controlling and managing scenes of the game
*/
/******************************************************************************/

#include "SceneTable.h"
#include "SceneManager.h"


//SceneManager SceneManager::getInstance()
//{
	//if (sceneManager_ == nullptr)
	//{
		//sceneManager_ = SceneManager(); // Or init?
		
		// Need to instantiate these objects first
		//prevScene_.Scene_Name(SCENE_INVALID);
		//currScene_.Scene_Name(SCENE_INVALID);
		//nextScene_.Scene_Name(SCENE_INITIAL);
	//}
	
	//return sceneManager_;
//}

/******************************************************************************/
/*!
    \fn SceneManager::SceneManager()

    \brief
      Constructor for Scene Manager
*/
/******************************************************************************/
SceneManager::SceneManager()
{
	
}


/******************************************************************************/
/*!
    \fn void SceneManager::Init()

    \brief
      Initialize Scene Manager
*/
/******************************************************************************/
void SceneManager::Init()
{
    //Debug Message: Init SceneManager
	
    
}

/******************************************************************************/
/*!
    \fn void SceneManager::Update(float dt)

    \brief
      Updates the scene manager system. Calls current scenes update
*/
/******************************************************************************/
void SceneManager::Update(float dt)
{
	//Debug Message: Update SceneManager
		
		currScene_.Update(dt);
    if (Changing())
    {
			// Shutdown current game state
			currScene_.Shutdown();
			currScene_.Unload();
			
			prevScene_ = currScene_;
			currScene_ = nextScene_;
			
			currScene_.Load();
      currScene_.Init();
    }
	 
}

/******************************************************************************/
/*!
    \fn void SceneManager::Shutdown()

    \brief
      Shutdown the Scene Manager
*/
/******************************************************************************/
void SceneManager::Shutdown()
{
    //Debug Message: Shutdown SceneManager
}

/******************************************************************************/
/*!
    \fn bool SceneManager::Is_Restarting()

    \brief
      Returns whether the scene is restarting

    \return
      True or false
*/
/******************************************************************************/
bool SceneManager::Is_Restarting()
{
    return nextScene_.Scene_Name() == SCENE_RESTART;
}

/******************************************************************************/
/*!
    \fn bool SceneManager::Is_Running()

    \brief
      Returns whether the scene is current running

    \return
      True or false
*/
/******************************************************************************/
bool SceneManager::Is_Running()
{
    return currScene_.Scene_Name() != SCENE_QUIT;
}

/******************************************************************************/
/*!
    \fn void SceneManager::Restart()

    \brief
      Restarts the current scene
*/
/******************************************************************************/
void SceneManager::Restart()
{
	if (SceneTable::Valid(currScene_.Scene_Name()))
	{
		currScene_.Shutdown();
		currScene_.Init();
	}
}

/******************************************************************************/
/*!
    \fn void SceneManager::Next_Scene(SceneState nextScene)

    \brief
      Sets the next scene
*/
/******************************************************************************/
void SceneManager::Next_Scene(SceneState nextScene)
{
    if (SceneTable::Valid(nextScene))
    {
        nextScene_.Scene_Name(nextScene);
    }
}


/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

bool SceneManager::Changing()
{
		return (currScene_.Scene_Name() != nextScene_.Scene_Name());
}