/******************************************************************************/
/*!
\file   CollisionDetection.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/17/19
\brief
  Basic collision detection
*/
/******************************************************************************/

#include "CollisionDetection.h"
#include "Collider.h"
#include "ColliderBox.h"

void CollisionDetection::Init()
{

}


void CollisionDetection::Tick(float dt)
{
    (dt);
    // Look through active objects
	//for (int i = 0; i < Colliders.Length(); i++)
	//{
	//	Collider* CollA = Colliders[i];
	//	if (CollA == nullptr)
	//	{
	//		continue;
	//	}
	//	for (int j = i + 1; j < Colliders.Length(); j++)
	//	{
	//		Collider* CollB = Colliders[j];
	//		if (CollB == nullptr) 
	//		{
	//			continue;
	//		}
	//
	//		ColliderCheck(CollA, CollB);
	//	}
	//}
}

void CollisionDetection::Shutdown()
{
    
}


void CollisionDetection::ColliderCheck(Collider* CollA, Collider* CollB) const
{
	switch (CollA->Type())
	{
	case Collider::COLLIDER_BOX:

		switch (CollB->Type())
		{
		case Collider::COLLIDER_BOX:
            BoxBoxCollision(CollA, CollB);
			break;
		case Collider::COLLIDER_CIRCLE:
			break;
		}
		break;
	case Collider::COLLIDER_CIRCLE:
		switch (CollB->Type())
		{
		case Collider::COLLIDER_BOX:
			break;
		case Collider::COLLIDER_CIRCLE:
			break;
		}
		break;
	}
}

void CollisionDetection::BoxBoxCollision(Collider* CollA, Collider* CollB) const
{
    ColliderBox* boxA = static_cast<ColliderBox*>(CollA);
    ColliderBox* boxB = static_cast<ColliderBox*>(CollB);


    TestAABBOverlap(&boxA->GetAABB(), &boxB->GetAABB());
}



/******************************************************************************/
/*!
    \fn bool CollisionDetection::TestAABBOverlap(AABB* a, AABB* b) const 

    \brief
      Tests overlap of two boxes
*/
/******************************************************************************/
bool CollisionDetection::TestAABBOverlap(AABB* a, AABB* b) const
{
    float diff1x = b->min.x - a->max.x;
    float diff1y = b->min.y - a->max.y;
    float diff2x = a->min.x - b->max.x;
    float diff2y = a->min.y - b->max.y;

    if (diff1x > 0.0f || diff1y > 0.0f)
        return false;
    if (diff2x > 0.0f || diff2y > 0.0f)
        return false;

    return true;
}