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

#include "Component.h"


/******************************************************************************/
/*!
  \class PhysicsBody
  \brief
    Interface for Physics component
*/
/******************************************************************************/
class PhysicsBody : public Component
{
public:
    PhysicsBody();
    PhysicsBody(const PhysicsBody& other);

    ~PhysicsBody();

    void Tick(float dt) { (dt); };

    void Handle_Message(const Message& msg) { (msg); };

    Component* Clone() const;

    const glm::vec2 Acceleration() const;

    const glm::vec2 Velocity() const;

    const glm::vec2 Old_Translation() const;

    float Rotational_Velocity() const;

    void Acceleration(const glm::vec2& acceleration);

    void Velocity(const glm::vec2& velocity);

    void Rotational_Velocity(float rotationalVelocity);

    void Update(float dt);

private:
    glm::vec2 velocity_;

    glm::vec2 acceleration_;

    glm::vec2 oldTranslation_;

    float rotationalVelocity_;

};