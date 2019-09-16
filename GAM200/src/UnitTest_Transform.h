/******************************************************************************/
/*!
\file   UnitTest_Transform.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Transform unit testing class.
*/
/******************************************************************************/

#pragma once

#include "Transform.h"
#include "UnitTest.h"

namespace UT
{
	/******************************************************************************/
    /*!
      \class TransformUT
      \brief
	    Test module for transform functionality.
    */
    /******************************************************************************/
	class TransformUT : public UnitTest
	{
	public:
		TransformUT();
		~TransformUT();
		virtual void RunTests();
	private:

		void test_Construction();
		void test_Translation();
		void test_Scale();
		void test_Rotation();
	};
}
