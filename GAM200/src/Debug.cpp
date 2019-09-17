/******************************************************************************/
/*!
\file   Debug.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Module for handling debug functionality
*/
/******************************************************************************/

#include "Debug.h"
#include "UnitTest.h"
#include "Message.h"


/******************************************************************************/
/*!
  \brief
    Constructor opens a log file upon creation

  \param filepath
    String name of the log file to write to

*/
/******************************************************************************/
Debug::Debug(std::string filepath, DBG_LV consoleSeverity, DBG_LV logSeverity)
{
	logSeverity_ = logSeverity;
	consoleSeverity_ = consoleSeverity;
    log_.open(filepath, std::ios::out);
    assert(log_.is_open());
}

/******************************************************************************/
/*!
  \brief
    Message handler for Debug Module

  \param msg
    Message being broadcast

*/
/******************************************************************************/
void Debug::Handle_Message(const Message& msg)
{
    switch (msg.type_)
    {
    case MSG_DEBUG:
    {
        const DebugMessage& strMsg = static_cast<const DebugMessage&>(msg); // cast to correct type
		if (strMsg.severity_ <= logSeverity_)
		{
			log_ << strMsg.mStr_ << '\n';  // log and print
		}

		if (strMsg.severity_ <= consoleSeverity_)
		{
			std::cout << strMsg.mStr_ << std::endl;
		}
        break;
    }
	case MSG_UTEST:
	{
		const UnitTestMessage& tstMsg = static_cast<const UnitTestMessage&>(msg);
		Run_Unit_Test(tstMsg.unit_);
		break;
	}
    default:
    {
        std::cout << "F U" << std::endl;
        break;
    }
    }
}

/******************************************************************************/
/*!
  \brief
	Runs a specific unit test.

  \param uType
	Specific unit to test.

*/
/******************************************************************************/
void Debug::Run_Unit_Test(UT::UType uType)
{
	UT::Test_Unit(uType);
}

/******************************************************************************/
/*!
  \brief
	Runs on tick.

  \param dt

*/
/******************************************************************************/
void Debug::Tick(float dt)
{
	(dt);
}
