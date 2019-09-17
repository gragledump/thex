/******************************************************************************/
/*!
\file   SceneManager.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/12/19
\brief
  System for controlling and managing scenes of the game
*/
/******************************************************************************/

#include "System.h"


typedef enum SceneState SceneState;

typedef class SceneTable SceneTable;
struct Message;


/******************************************************************************/
/*!
  \class SceneManager
  \brief
    Interface for the SceneManager system
*/
/******************************************************************************/
class SceneManager : public System
{
public:

	SceneManager();
	~SceneManager() {};

	// Get the singleton instance of scene manager
	//static SceneManager getInstance();

	void Tick(float dt) { (dt); };

	void Handle_Message(const Message& msg) { (msg); };

		
    // Initialize the Scene Manager system
    void Init();

    // Update the scene manager
    void Update(float dt);

    // Shutdown the scene manager
    void Shutdown();

    // Returns whether the scene is restarting
    bool Is_Restarting();

    // Returns whether the game is running
    bool Is_Running();

	void Restart();

    // Set the next scene
    void Next_Scene(SceneState nextScene);

private:   

    // Base class for scenes
    SceneTable currScene_;
    SceneTable prevScene_;
    SceneTable nextScene_;
		
	// Singleton instance of manager
    //static SceneManager sceneManager_;
    
    
    // Returns whether the scene in changing
    bool Changing();

};