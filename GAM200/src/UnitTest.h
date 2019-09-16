/******************************************************************************/
/*!
\file   UnitTest.h
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
    Interface for running unit tests on individual engine systems and
	components. Derived classes can be created with individual tests to run.
	Unit tests should be focused on 1 specefic functionality. Look at
	UnitTest_Transform for an example.
*/
/******************************************************************************/

#pragma once

namespace UT
{
	enum UType
	{
		C_TRANSFORM,
		UNIT_MAX
	};

	void Test_Unit(UType unit);

	/******************************************************************************/
    /*!
      \class UnitTest
      \brief
	    Abstract unit testing class.
    */
    /******************************************************************************/
	class UnitTest
	{
	public:
		virtual ~UnitTest() {}
		virtual void RunTests() = 0;
	};
}
