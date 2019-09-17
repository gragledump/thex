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

#include "Bounds.h" 

/******************************************************************************/
/*!
    \fn Bounds::Bounds() : Component(CMP_BOUNDS)

    \brief
      Constructor for Bounds component. Initializes values to 0

*/
/******************************************************************************/
Bounds::Bounds() : Component(CMP_BOUNDS)
{
    type_ = BOUNDS_INVALID;
    position_ = { 0.0f, 0.0f };
    scale_ = { 0.0f, 0.0f };
    offset_ = { 0.0f, 0.0f };
    rotation_ = 0.0f;
    parent_ = nullptr;
}

/******************************************************************************/
/*!
  \fn Bounds::Bounds(BoundsType type) : Component(CMP_BOUNDS)

  \brief
    Constructor for Bounds component. Sets type

  \param type
    Type of bounds
*/
/******************************************************************************/
Bounds::Bounds(BoundsType type) : Component(CMP_BOUNDS)
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
  \fn Bounds::Bounds(const Bounds& other) : Component(other)

  \brief
    Copy constructor for Bounds constructor

  \param other
    Bounds component to copy
*/
/******************************************************************************/
Bounds::Bounds(const Bounds& other) : Component(other)
{
    *this = other;
}

Bounds::~Bounds()
{
  
}

/******************************************************************************/
/*!
  \fn Component* Bounds::Clone() const

  \brief
    Used to make a clone of components
*/
/******************************************************************************/
Component* Bounds::Clone() const
{
    return new Bounds(*this);
}

/******************************************************************************/
/*!
  \fn Bounds::BoundsType Bounds::Type() const

  \brief
    Returns the type of the bounds
*/
/******************************************************************************/
Bounds::BoundsType Bounds::Type() const
{
    return type_;
}

/******************************************************************************/
/*!
  \fn void Bounds::Type(BoundsType type)

  \brief
    Sets the type of bounds
*/
/******************************************************************************/
void Bounds::Type(BoundsType type)
{
    type_ = type;
}

/******************************************************************************/
/*!
  \fn glm::vec2& Bounds::Position() const

  \brief
    Returns the position of the bounds
*/
/******************************************************************************/
glm::vec2 Bounds::Position() const
{
    return position_;
}

/******************************************************************************/
/*!
  \fn void Bounds::Position(glm::vec2& position)

  \brief
    Sets position of bounds
*/
/******************************************************************************/
void Bounds::Position(glm::vec2& position)
{
    position_ = position;
}


/******************************************************************************/
/*!
  \fn glm::vec2& Bounds::Scale() const

  \brief
    Returns the scale of the bounds
*/
/******************************************************************************/
glm::vec2 Bounds::Scale() const
{
    return scale_;
}

/******************************************************************************/
/*!
  \fn void Bounds::Scale(glm::vec2& scale)

  \brief
    Sets scale of bounds
*/
/******************************************************************************/
void Bounds::Scale(glm::vec2& scale)
{
    scale_ = scale;
}

/******************************************************************************/
/*!
  \fn float Bounds::Rotation() const

  \brief
    Returns the rotation of bounds
*/
/******************************************************************************/
float Bounds::Rotation() const
{
    return rotation_;
}

/******************************************************************************/
/*!
  \fn void Bounds::Rotation(float rotation)

  \brief
    Sets the rotation of bounds
*/
/******************************************************************************/
void Bounds::Rotation(float rotation)
{
  rotation_ = rotation;
}


/******************************************************************************/
/*!
  \fn void Bounds::Update(float dt)

  \brief
    

  \param dt
    Time in between frames
*/
/******************************************************************************/
void Bounds::Update(float dt)
{

}
