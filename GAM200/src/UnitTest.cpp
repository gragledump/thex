/******************************************************************************/
/*!
\file   Debug.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
   Implementation for engine unit tests.
*/
/******************************************************************************/

#include "UnitTest_Transform.h"
#include "UnitTest.h"

namespace UT
{
	/******************************************************************************/
	/*!
	  \brief
		 Runs a specific unit test.

	  \param unit
  		 Specific unit to test.

	*/
	/******************************************************************************/
	void Test_Unit(UType unit)
	{
		switch (unit)
		{
		case C_TRANSFORM:
		{
			TransformUT uTest;
			uTest.RunTests();
			break;
		}
		}
	}
}
