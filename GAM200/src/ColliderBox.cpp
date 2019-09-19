/******************************************************************************/
/*!
\file   ColliderBox.cpp
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/17/19
\brief
  Class for box collider data
*/
/******************************************************************************/

#include "ColliderBox.h"
#include "Collider.h"



/******************************************************************************/
/*!
    \fn ColliderBox::ColliderBox()

    \brief
      Constructor for box collider
*/
/******************************************************************************/
ColliderBox::ColliderBox()
{
	
}


ColliderBox::ColliderBox(const Transform& parent) : Collider(parent)
{
    SetAABB();
}

AABB ColliderBox::GetAABB()
{
    return box_;
}







void ColliderBox::SetAABB()
{
    if (Parent())
    {
        box_.min.x = Position()->x - (Scale()->x / 2.0f);
        box_.min.y = Position()->y - (Scale()->y / 2.0f);
        box_.max.x = Position()->x + (Scale()->x / 2.0f);
        box_.max.y = Position()->y + (Scale()->y / 2.0f);
    }
}