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

SceneManager::SceneManager()
{
	
}

void SceneManager::Init()
{
    //Debug Message: Init SceneManager
	
    
}


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

void SceneManager::Shutdown()
{
    //Debug Message: Shutdown SceneManager
}

bool SceneManager::Is_Restarting()
{
    return nextScene_.Scene_Name() == SCENE_RESTART;
}

bool SceneManager::Is_Running()
{
    return currScene_.Scene_Name() != SCENE_QUIT;
}

void SceneManager::Restart()
{
	if (SceneTable::Valid(currScene_.Scene_Name()))
	{
		currScene_.Shutdown();
		currScene_.Init();
	}
}


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