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
#include "Message.h"


/******************************************************************************/
/*!
  \brief
    Constructor opens a log file upon creation

  \param filepath
    String name of the log file to write to

*/
/******************************************************************************/
Debug::Debug(std::string filepath)
{
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
    case MSG_STR:
    {
        const StrMessage& strMsg = static_cast<const StrMessage&>(msg); // cast to correct type
          // log and print
        log_ << strMsg.mStr_ << '\n';
        std::cout << strMsg.mStr_ << std::endl;
        break;
    }
    default:
    {
        std::cout << "F U" << std::endl;
        break;
    }
    }
}

void Debug::Tick(float dt)
{
	(dt);
}
