/******************************************************************************/
/*!
\file   Collider.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/17/19
\brief
  Basic collision for a game object. Derived from Component
*/
/******************************************************************************/

#pragma once

#include "Component.h"

class Transform;

/******************************************************************************/
/*!
  \class Collider
  \brief
    Interface for Collider component
*/
/******************************************************************************/
class Collider : public Component
{
public:
	typedef enum ColliderType
	{
		COLLIDER_INVALID = -1,
		COLLIDER_BOX,
		COLLIDER_CIRCLE,
		COLLIDER_COUNT
	}ColliderType;

    Collider();
    Collider(ColliderType type);
    Collider(const Collider& other);
    Collider(const Transform& parent);
    ~Collider();
    Component* Clone() const;

    void Tick(float dt) { (dt); };
    void Handle_Message(const Message& msg) { (msg); };

    ColliderType Type() const;
    void Type(ColliderType type);

    const glm::vec2* Position() const;

    const glm::vec2* Scale() const;
    void Scale(const glm::vec2& size);

    float Rotation() const;

    const Transform* Parent();



private:
    ColliderType type_;

    const glm::vec2* position_;

    const glm::vec2* scale_;

    glm::vec2 offset_;

    const float* rotation_;

    const Transform* parent_;

    
    void SetTransform();

};