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
    ~Collider();
    Component* Clone() const;

    void Tick(float dt) { (dt); };
    void Handle_Message(const Message& msg) { (msg); };

    void Update(float dt);

    ColliderType Type() const;
    void Type(ColliderType type);

    glm::vec2 Position() const;
    void Position(glm::vec2& position);

    glm::vec2 Scale() const;
    void Scale(glm::vec2& size);

    float Rotation() const;
    void Rotation(float rotation);



private:
    ColliderType type_;

    glm::vec2 position_;

    glm::vec2 offset_;

    glm::vec2 scale_;

    float rotation_;

    Transform* parent_;

};