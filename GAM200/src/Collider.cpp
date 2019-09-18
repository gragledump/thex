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

#include "Collider.h" 

/******************************************************************************/
/*!
    \fn Collider::Collider() : Component(CMP_COLLIDER)

    \brief
      Constructor for Collider component. Initializes values to 0

*/
/******************************************************************************/
Collider::Collider() : Component(CMP_COLLIDER)
{
    type_ = COLLIDER_INVALID;
    position_ = { 0.0f, 0.0f };
    scale_ = { 0.0f, 0.0f };
    offset_ = { 0.0f, 0.0f };
    rotation_ = 0.0f;
    parent_ = nullptr;
}

/******************************************************************************/
/*!
  \fn Collider::Collider(ColliderType type) : Component(CMP_COLLIDER)

  \brief
    Constructor for Collider component. Sets type

  \param type
    Type of Collider
*/
/******************************************************************************/
Collider::Collider(ColliderType type) : Component(CMP_COLLIDER)
{
    type_ = type;
    position_ = { 0.0f, 0.0f };
    scale_ = { 0.0f, 0.0f };
    offset_ = { 0.0f, 0.0f };
    rotation_ = 0.0f;
    parent_ = nullptr;
}

/******************************************************************************/
/*!
  \fn Collider::Collider(const Collider& other) : Component(other)

  \brief
    Copy constructor for Collider constructor

  \param other
    Collider component to copy
*/
/******************************************************************************/
Collider::Collider(const Collider& other) : Component(other)
{
    *this = other;
}

Collider::~Collider()
{
  
}

/******************************************************************************/
/*!
  \fn Component* Collider::Clone() const

  \brief
    Used to make a clone of components
*/
/******************************************************************************/
Component* Collider::Clone() const
{
    return new Collider(*this);
}

/******************************************************************************/
/*!
  \fn Collider::ColliderType Collider::Type() const

  \brief
    Returns the type of the Collider
*/
/******************************************************************************/
Collider::ColliderType Collider::Type() const
{
    return type_;
}

/******************************************************************************/
/*!
  \fn void Collider::Type(ColliderType type)

  \brief
    Sets the type of Collider
*/
/******************************************************************************/
void Collider::Type(ColliderType type)
{
    type_ = type;
}

/******************************************************************************/
/*!
  \fn glm::vec2& Collider::Position() const

  \brief
    Returns the position of the Collider
*/
/******************************************************************************/
glm::vec2 Collider::Position() const
{
    return position_;
}

/******************************************************************************/
/*!
  \fn void Collider::Position(glm::vec2& position)

  \brief
    Sets position of Collider
*/
/******************************************************************************/
void Collider::Position(glm::vec2& position)
{
    position_ = position;
}


/******************************************************************************/
/*!
  \fn glm::vec2& Collider::Scale() const

  \brief
    Returns the scale of the Collider
*/
/******************************************************************************/
glm::vec2 Collider::Scale() const
{
    return scale_;
}

/******************************************************************************/
/*!
  \fn void Collider::Scale(glm::vec2& scale)

  \brief
    Sets scale of Collider
*/
/******************************************************************************/
void Collider::Scale(glm::vec2& scale)
{
    scale_ = scale;
}

/******************************************************************************/
/*!
  \fn float Collider::Rotation() const

  \brief
    Returns the rotation of Collider
*/
/******************************************************************************/
float Collider::Rotation() const
{
    return rotation_;
}

/******************************************************************************/
/*!
  \fn void Collider::Rotation(float rotation)

  \brief
    Sets the rotation of Collider
*/
/******************************************************************************/
void Collider::Rotation(float rotation)
{
  rotation_ = rotation;
}


/******************************************************************************/
/*!
  \fn void Collider::Update(float dt)

  \brief
    

  \param dt
    Time in between frames
*/
/******************************************************************************/
void Collider::Update(float dt)
{

}
