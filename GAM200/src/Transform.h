/******************************************************************************/
/*!
\file   Debug.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Interface for Transform components.
*/
/******************************************************************************/

#pragma once

#include "Component.h"

struct Message;

/******************************************************************************/
/*!
  \class Component
  \brief
	Interface for the transform component. Uses glm vector/matrix constructs.
*/
/******************************************************************************/
class Transform : public Component
{
public:
	Transform(float x, float y);
	Transform(const Transform& other);

	const glm::mat3& Mtx();

	const glm::vec2& Translation() const;
	void Translation(const glm::vec2& trans);

	float Rotation() const;
	void Rotation(float rot);

	const glm::vec2& Scale() const;
	void Scale(const glm::vec2& scale);

private:
	void CleanMtx();

	glm::vec2 translation_;
	float     rotation_;
	glm::vec2 scale_;
	glm::mat3 mtx_;
	bool      isDirty_;
};
