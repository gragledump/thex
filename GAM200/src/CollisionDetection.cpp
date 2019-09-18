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
	//		ColliderCheck(*CollA, *CollB);
	//	}
	//}
}

void CollisionDetection::Shutdown()
{

}


void CollisionDetection::ColliderCheck(const Collider& CollA, const Collider& CollB) const
{
	switch (CollA.Type())
	{
	case Collider::COLLIDER_BOX:

		switch (CollB.Type())
		{
		case Collider::COLLIDER_BOX:
			break;
		case Collider::COLLIDER_CIRCLE:
			break;
		}
		break;
	case Collider::COLLIDER_CIRCLE:
		switch (CollB.Type())
		{
		case Collider::COLLIDER_BOX:
			break;
		case Collider::COLLIDER_CIRCLE:
			break;
		}
		break;
	}
}

void CollisionDetection::BoxBoxCollision(const Collider& CollA, const Collider& CollB) const
{

}