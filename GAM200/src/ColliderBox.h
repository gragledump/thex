/******************************************************************************/
/*!
\file   ColliderBox.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/17/19
\brief
  Class for box collider data

  Source: 
  AABB - https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects
*/
/******************************************************************************/

#include "Collider.h"


class Transform;

typedef struct AABB
{
    glm::vec2 min;
    glm::vec2 max;
}AABB;

/******************************************************************************/
/*!
  \class ColliderBox
  \brief
    Interface for the ColliderBox component
*/
/******************************************************************************/
class ColliderBox : public Collider
{
public:

	ColliderBox();
    ColliderBox(const Transform& parent);
	~ColliderBox() {};


    AABB GetAABB();

private:   
    AABB box_;
  
    void SetAABB();
};