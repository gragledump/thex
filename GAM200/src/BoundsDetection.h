/******************************************************************************/
/*!
\file   PhysicsBody.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/16/19
\brief
  Basic physics for a game object. Derived from Component
*/
/******************************************************************************/

#pragma once

#include "System.h"

/******************************************************************************/
/*!
  \class BoundsDetection
  \brief
    Interface for Bounds collision detection system
*/
/******************************************************************************/
class BoundsDetection : public System
{
public:
    BoundsDetection() {};
    ~BoundsDetection() {};

    void Tick(float dt) { (dt); };
    void Handle_Message(const Message& msg) { (msg); };

    void Init();

    void Update(float dt);

    void Shutdown();


private:


};