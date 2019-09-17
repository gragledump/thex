/******************************************************************************/
/*!
\file   Transform.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Implementation for Transform components.
*/
/******************************************************************************/

#include "Transform.h"
#include "Debug.h"

/******************************************************************************/
/*!
  \brief
	Constructor from an x + y coordinate. Scale and rotation are set to default

  \param x
	
  \param y

*/
/******************************************************************************/
Transform::Transform(float x, float y) : Component(CMP_TRANSFORM),
	translation_(glm::vec2(x, y)), scale_(glm::vec2(1.f, 1.f)), rotation_(0.f), isDirty_(true)
{
}

/******************************************************************************/
/*!
  \brief
	Constructor from a translation vector. Scale and rotation are set to default

  \param translation
    glm vec2 representing a translation

*/
/******************************************************************************/
Transform::Transform(glm::vec2 translation) : Component(CMP_TRANSFORM),
	translation_(translation), scale_(glm::vec2(1.f, 1.f)), rotation_(0.f), isDirty_(true)
{
}

/******************************************************************************/
/*!
  \brief
	Constructor from translation and scale vectors. Rotation set to default

  \param translation
	glm vec2 representing a translation

  \param scale
	glm vec2 representing scale

*/
/******************************************************************************/
Transform::Transform(glm::vec2 translation, glm::vec2 scale) : Component(CMP_TRANSFORM),
	translation_(translation), scale_(scale), rotation_(0.f), isDirty_(true)
{
}

/******************************************************************************/
/*!
  \brief
	Constructor from translation and scale vectors and a rotation in radians.

  \param translation
	glm vec2 representing a translation

  \param scale
	glm vec2 representing scale

  \param rotation
    rotation value in radians

*/
/******************************************************************************/
Transform::Transform(glm::vec2 translation, glm::vec2 scale, float rotation) : Component(CMP_TRANSFORM),
	translation_(translation), scale_(scale), rotation_(rotation), isDirty_(true)
{
}

/******************************************************************************/
/*!
  \brief
	Copy Constructor for Transform.

  \param other
	Transform to copy

*/
/******************************************************************************/
Transform::Transform(const Transform& other) : Component(other)
{
	*this = other;
}

/******************************************************************************/
/*!
  \brief
	Retrieve the glm 3x3 matrix from the transform, recalculating if necessary.

*/
/******************************************************************************/
const glm::mat3& Transform::Mtx()
{
	if (isDirty_)
	{
		CleanMtx();
	}
	return mtx_;
}

/******************************************************************************/
/*!
  \brief
	Retrieve the translation.
*/
/******************************************************************************/
const glm::vec2& Transform::Translation() const
{
	return translation_;
}

/******************************************************************************/
/*!
  \brief
	Set the translation.

  \param trans
	glm vec2 to set the translation

*/
/******************************************************************************/
void Transform::Translation(const glm::vec2& trans)
{
	translation_ = trans;
	isDirty_ = true;
}

/******************************************************************************/
/*!
  \brief
	Retrieve the rotation.
*/
/******************************************************************************/
float Transform::Rotation() const
{
	return rotation_;
}

/******************************************************************************/
/*!
  \brief
	Set the rotation.

  \param rot
	float to set the rotation

*/
/******************************************************************************/
void Transform::Rotation(float rot)
{
	rotation_ = rot;
	isDirty_ = true;
}

/******************************************************************************/
/*!
  \brief
	Retrieve the scale.
*/
/******************************************************************************/
const glm::vec2& Transform::Scale() const
{
	return scale_;
}

/******************************************************************************/
/*!
  \brief
	Set the scale.

  \param scale
	glm vec2 to set the scale

*/
/******************************************************************************/
void Transform::Scale(const glm::vec2& scale)
{
	scale_ = scale;
	isDirty_ = true;
}

/******************************************************************************/
/*!
  \brief
	Recalculates a fresh matrix for a dirty transform.

*/
/******************************************************************************/
void Transform::CleanMtx()
{
	glm::mat3 s = scale(glm::mat3(1.f), scale_);
	glm::mat3 r = rotate(glm::mat3(1.f), rotation_);
	glm::mat3 t = translate(glm::mat3(1.f), translation_);

	mtx_ = t * (r * s);

	isDirty_ = false;
}
