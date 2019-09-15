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

Transform::Transform(float x, float y)
{
	isDirty_ = true;
}

Transform::Transform(const Transform& other)
{
	*this = other;
}

const glm::mat3& Transform::Mtx()
{
	if (isDirty_)
		CleanMtx();
	return mtx_;
}

const glm::vec2& Transform::Translation() const
{
	return translation_;
}

void Transform::Translation(const glm::vec2& trans)
{
	translation_ = trans;
	isDirty_ = true;
}

float Transform::Rotation() const
{
	return rotation_;
}

void Transform::Rotation(float rot)
{
	rotation_ = rot;
	isDirty_ = true;
}

const glm::vec2& Transform::Scale() const
{
	return scale_;
}

void Transform::Scale(const glm::vec2& scale)
{
	scale_ = scale;
	isDirty_ = true;
}


void Transform::CleanMtx()
{
	glm::mat3 s = scale(glm::mat3(), scale_);
	glm::mat3 r = rotate(glm::mat3(), rotation_);
	glm::mat3 t = translate(glm::mat3(), translation_);

	mtx_ = t * (r * s);
	isDirty_ = false;
}
