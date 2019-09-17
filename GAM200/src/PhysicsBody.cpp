/******************************************************************************/
/*!
\file   PhysicsBody.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/16/19
\brief
  Basic PhysicsBody for a game object. Derived from Component
*/
/******************************************************************************/

#include "PhysicsBody.h"

/******************************************************************************/
/*!
    \fn PhysicsBody::PhysicsBody() : Component(Component::CMP_PhysicsBody)

    \brief
      Constructor for PhysicsBody component. Initializes values to 0

*/
/******************************************************************************/
PhysicsBody::PhysicsBody() : Component(CMP_PHYSICS)
{
  acceleration_ = { 0.0f, 0.0f };
  velocity_ = { 0.0f, 0.0f };
  oldTranslation_ = { 0.0f, 0.0f };
  rotationalVelocity_ = 0;
}

/******************************************************************************/
/*!
  \fn PhysicsBody::PhysicsBody(const PhysicsBody& other) : Component(other)

  \brief
    Copy constructor for PhysicsBody constructor

  \param other
    PhysicsBody component to copy
*/
/******************************************************************************/
PhysicsBody::PhysicsBody(const PhysicsBody& other) : Component(other)
{
  *this = other;
}

PhysicsBody::~PhysicsBody()
{
  
}

/******************************************************************************/
/*!
  \fn ComponentPtr PhysicsBody::Clone() const

  \brief
    Used to make a clone of components
*/
/******************************************************************************/
Component* PhysicsBody::Clone() const
{
  return new PhysicsBody(*this);
}

/******************************************************************************/
/*!
  \fn const glm::vec2& PhysicsBody::Acceleration() const

  \brief
    Returns the acceleration of the object
    
  \return
    Acceleration of the object
*/
/******************************************************************************/
const glm::vec2 PhysicsBody::Acceleration() const
{
  return acceleration_;
}

/******************************************************************************/
/*!
  \fn const glm::vec2& PhysicsBody::Velocity() const

  \brief
    Returns the velocity of the object
    
  \return
    Velocity of the object
*/
/******************************************************************************/
const glm::vec2 PhysicsBody::Velocity() const
{
  return velocity_;
}

/******************************************************************************/
/*!
  \fn const glm::vec2& PhysicsBody::Old_Translation() const

  \brief
    Returns the previous calculated position of the object. Used to resolve 
    collisions
    
  \return
    Previous position of object
*/
/******************************************************************************/
const glm::vec2 PhysicsBody::Old_Translation() const
{
  return oldTranslation_;
}

/******************************************************************************/
/*!
  \fn float PhysicsBody::Rotational_Velocity() const

  \brief
    Returns the rotation velocity of an object
    
  \return
    Rotational velocity
*/
/******************************************************************************/
float PhysicsBody::Rotational_Velocity() const
{
  return rotationalVelocity_;
}

/******************************************************************************/
/*!
  \fn void PhysicsBody::Acceleration(const glm::vec2& acceleration)

  \brief
    Sets the acceleration of object

  \param acceleration
    Acceleration to set
*/
/******************************************************************************/
void PhysicsBody::Acceleration(const glm::vec2& acceleration)
{
  acceleration_ = acceleration;
}

/******************************************************************************/
/*!
  \fn void PhysicsBody::Velocity(const glm::vec2& velocity)

  \brief
    Sets the velocity of object

  \param velocity
    Velocity to set
*/
/******************************************************************************/
void PhysicsBody::Velocity(const glm::vec2& velocity)
{
  velocity_ = velocity;
}

/******************************************************************************/
/*!
  \fn void PhysicsBody::Rotational_Velocity(float rotationalVelocity)

  \brief
    Sets the rotational velocity of object

  \param rotationalVelocity
    Rotational velocity to set
*/
/******************************************************************************/
void PhysicsBody::Rotational_Velocity(float rotationalVelocity)
{
  rotationalVelocity_ = rotationalVelocity;
}

/******************************************************************************/
/*!
  \fn void PhysicsBody::Update(float dt)

  \brief
    Update the position and velocity of an object

  \param dt
    Time in between frames
*/
/******************************************************************************/
void PhysicsBody::Update(float dt)
{
  //TransformPtr transform = Parent()->Has(Transform);
  //
  //if (transform)
  //{
  //  static Vector2D newVelocity;
  //  static Vector2D position;
  //  float rotVelocity = transform->Rotation();
  //  
  //  rotVelocity += RotationalVelocity_ * dt;
  //  newVelocity = Acceleration_;
  //  position = *transform->Translation();
  //  
  //  newVelocity = (newVelocity * dt) + Velocity_;
  //  Drag?
  //  Velocity_ = newVelocity;
  //  
  //  position = (newVelocity * dt) + position;
  //  
  //  transform->Translation(&position);
  //  transform->Rotation(rotVelocity);
    
  //}
}
