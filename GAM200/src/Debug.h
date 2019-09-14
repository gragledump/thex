/******************************************************************************/
/*!
\file   Debug.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Module for handling debug functionality
*/
/******************************************************************************/

#pragma once

#include "System.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

struct Message;

/******************************************************************************/
/*!
  \class Debug
  \brief
    Class that manages Debug functionality
*/
/******************************************************************************/
class Debug : public System
{
public:

    Debug(std::string filepath);

	void Tick(float dt);

    void Handle_Message(const Message& msg);

private:
    std::fstream log_;
};
