/******************************************************************************/
/*!
\file   CollisionDetection.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/16/19
\brief
  Collision detection system for game objects
*/
/******************************************************************************/

#pragma once

#include "System.h"

struct Message;
struct AABB;
class Collider;

/******************************************************************************/
/*!
  \class CollisionDetection
  \brief
    Interface for collision detection system
*/
/******************************************************************************/
class CollisionDetection : public System
{
public:
    CollisionDetection() {};
    ~CollisionDetection() {};

    void Tick(float dt);
    void Handle_Message(const Message& msg) { (msg); };

    void Init();

    void Shutdown();


private:
	void ColliderCheck(Collider* CollA, Collider* CollB) const;
	void BoxBoxCollision(Collider* CollA, Collider* CollB) const;
    bool TestAABBOverlap(AABB* a, AABB* b) const;
};