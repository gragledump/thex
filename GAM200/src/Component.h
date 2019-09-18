/******************************************************************************/
/*!
\file   Component.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Base component class for implementing entity-component architecture.
*/
/******************************************************************************/

#pragma once

struct Message;

/******************************************************************************/
/*!
  \enum ComponentType
  \brief
    Enums for different components. Put in order that they should be updated
*/
/******************************************************************************/
typedef enum ComponentType
{
    CMP_INVALID = -1,

    CMP_COLLIDER,
    CMP_PHYSICS,
    CMP_TRANSFORM,

    CMP_COUNT
}ComponentType;

/******************************************************************************/
/*!
  \class Component
  \brief
    Interface for components.
*/
/******************************************************************************/
class Component
{
public:
    Component(ComponentType type) : type_(type) {}; // Used to construct components
	virtual ~Component() {}
	virtual void Tick(float dt) = 0;                      // Function to be called each tick
	virtual void Handle_Message(const Message& msg) = 0;  // Message Handler
    virtual void Update(float dt) { (dt); };

private:
    ComponentType type_;
};
