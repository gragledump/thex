/******************************************************************************/
/*!
\file   SceneTable.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/12/19
\brief
  Parent class for individual scenes
*/
/******************************************************************************/

#pragma once

typedef enum SceneState
{
    SCENE_INVALID = -3,
    SCENE_RESTART,
    SCENE_QUIT,

    SCENE_TEST = 0,

    SCENE_COUNT,

    SCENE_INITIAL = SCENE_TEST
}SceneState;



class SceneTable
{
public:

	SceneTable();
    SceneTable(SceneState sceneName);

    // Returns whether the scene is valid
    static bool Valid(SceneState scene);

	void Scene_Name(SceneState scene);

	SceneState Scene_Name();

	virtual void Load() {};

	virtual void Init() {};

	virtual void Update(float dt) {(dt);};

	virtual void Shutdown() {};

	virtual void Unload() {};

private:

	SceneState sceneName_;

};