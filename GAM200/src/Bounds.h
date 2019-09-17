/******************************************************************************/
/*!
\file   Bounds.h
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
  \class Bounds
  \brief
    Interface for Bounds component
*/
/******************************************************************************/
class Bounds : public Component
{
public:
    typedef enum BoundsType
    {
        BOUNDS_INVALID = -1,

        BOUNDS_BOX,

        BOUNDS_CIRCLE,

        BOUNDS_COUNT
    }BoundsType;

    Bounds();
    Bounds(BoundsType type);
    Bounds(const Bounds& other);
    ~Bounds();
    Component* Clone() const;

    void Tick(float dt) { (dt); };
    void Handle_Message(const Message& msg) { (msg); };

    void Update(float dt);

    BoundsType Type() const;
    void Type(BoundsType type);

    glm::vec2 Position() const;
    void Position(glm::vec2& position);

    glm::vec2 Scale() const;
    void Scale(glm::vec2& size);

    float Rotation() const;
    void Rotation(float rotation);



private:
    BoundsType type_;

    glm::vec2 position_;

    glm::vec2 offset_;

    glm::vec2 scale_;

    float rotation_;

    Transform* parent_;

};