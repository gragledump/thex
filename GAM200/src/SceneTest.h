/******************************************************************************/
/*!
\file   SceneTest.h
\author Bennett Ewanchyna
\par    email: bennett.e@digipen.edu
\par	GAM200 Project
\date   9/12/19
\brief

*/
/******************************************************************************/

#pragma once

#include "SceneTable.h"

class SceneTest : public SceneTable
{
public:

    void Init();

    void Load();

    void Update(float dt);

    void Shutdown();

    void Unload();
};