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
#include "UnitTest.h"
#include "Message.h"

struct Message;

/******************************************************************************/
/*!
  \class Debug
  \brief
    System that manages Debug functionality, including logging and unit tests.
*/
/******************************************************************************/
class Debug : public System
{
public:
	enum DBG_LV
	{
		QUIET   = 0,
		ERROR   = 1,
		WARNING = 2,
		INFO    = 3,
		VERBOSE = 4,
		DEBUG   = 5
	};

    Debug(std::string filepath, DBG_LV consoleSeverity, DBG_LV logSeverity);

	void Tick(float dt);

    void Handle_Message(const Message& msg);

private:
	void Run_Unit_Test(UT::UType uniType);

	std::fstream log_;
	DBG_LV logSeverity_;
	DBG_LV consoleSeverity_;
};

/******************************************************************************/
/*!
  \class DebugMessage
  \brief
	Message with a formatted std::string payload, for debugging purposes.
	Template variadic code added from https://stackoverflow.com/a/26221725
	under CC0 1.0
*/
/******************************************************************************/
struct DebugMessage : public Message
{
	template<typename ... Args>
	DebugMessage(Debug::DBG_LV severity, const std::string& format, Args ... args) : Message(MSG_DEBUG, nullptr)
	{
		size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1;
		std::unique_ptr<char[]> buf(new char[size]);
		snprintf(buf.get(), size, format.c_str(), args ...);
		mStr_ = std::string(buf.get(), buf.get() + size - 1);
		severity_ = severity;
	}

	std::string mStr_;
	Debug::DBG_LV severity_;

private:
	DebugMessage() = delete;
};

/******************************************************************************/
/*!
  \class UnitTestMessage
  \brief
	Simple message to trigger a unit test.
*/
/******************************************************************************/
struct UnitTestMessage : public Message
{
	UnitTestMessage(UT::UType testUnit) : Message(MSG_UTEST, nullptr), unit_(testUnit) {}

	UT::UType unit_;
private:
	UnitTestMessage() = delete;
};
