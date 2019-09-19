/******************************************************************************/
/*!
\file   SceneTable.cpp
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/12/19
\brief

*/
/******************************************************************************/

#include "SceneTable.h"

/******************************************************************************/
/*!
  \brief
	Constructor sets scene name

*/
/******************************************************************************/
SceneTable::SceneTable() : sceneName_(SCENE_INVALID)
{
	
}

SceneTable::SceneTable(SceneState sceneName) : sceneName_(sceneName)
{

}

/******************************************************************************/
/*!
  \brief
	Sets the scene name

  \param scene
	The scene to set

*/
/******************************************************************************/
void SceneTable::Scene_Name(SceneState scene)
{
	sceneName_ = scene;
}


/******************************************************************************/
/*!
  \brief
	Returns the scene name

  \return
	The current scene
*/
/******************************************************************************/
SceneState SceneTable::Scene_Name()
{
	return sceneName_;
}

/******************************************************************************/
/*!
  \brief
	Determines if the given scene is valid

  \param scene
    The scene to check validity

  \return
	True or false if the scene is valid
*/
/******************************************************************************/
bool SceneTable::Valid(SceneState scene)
{
    return ((0 <= scene) && (scene < SCENE_COUNT));
}