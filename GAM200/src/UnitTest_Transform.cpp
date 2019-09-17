/******************************************************************************/
/*!
\file   UnitTest_Transform.cpp
\author Gray Bangs
\par    email: gray.bangs@digipen.edu
\par	GAM200 Project
\date   9/09/19
\brief
  Transform unit testing class.
*/
/******************************************************************************/

#include "UnitTest.h"
#include "UnitTest_Transform.h"
#include "Debug.h"

namespace UT
{
	/******************************************************************************/
    /*!
      \brief
    	Default constructor.

    */
    /******************************************************************************/
	TransformUT::TransformUT()
	{
	}

	/******************************************************************************/
	/*!
      \brief
	    Default destructor.

    */
    /******************************************************************************/
	TransformUT::~TransformUT()
	{
	}

	/******************************************************************************/
	/*!
	  \brief
		Runs tests.

	*/
	/******************************************************************************/
	void TransformUT::RunTests()
	{
		test_Construction();
		test_Translation();
		test_Scale();
		test_Rotation();
	}

	/******************************************************************************/
/*!
  \brief
	Runs tests.

*/
/******************************************************************************/
	void TransformUT::test_Construction()
	{
		Transform* transform = new Transform(0.f, 0.f);
		assert(transform);

		delete transform;

		transform = new Transform(glm::vec2(0.f, 0.f));
		assert(transform);

		delete transform;

		transform = new Transform(glm::vec2(0.f, 0.f), glm::vec2(69.f, 420.f));
		assert(transform);

		delete transform;

		transform = new Transform(glm::vec2(0.f, 0.f), glm::vec2(69.f, 420.f), 9001.f);
		assert(transform);

		delete transform;
	}

	/******************************************************************************/
/*!
  \brief
	Runs tests.

*/
/******************************************************************************/
	void TransformUT::test_Translation()
	{
		glm::vec2 translation(0.f, 0.f);
		Transform* transform = new Transform(translation);

		if (transform->Translation().x != 0.f || transform->Translation().y != 0.f)
		{
			DebugMessage msg(Debug::ERROR, "Translation Incorrectly Initialized!\nx = %f\ny = %f\n", transform->Translation().x, transform->Translation().y);
			msg.Send();
			assert(false);
		}

		translation = glm::vec2(69.f, 420.f);
		transform->Translation(translation);

		if (transform->Translation().x != 69.f || transform->Translation().y != 420.f)
		{
			DebugMessage msg(Debug::ERROR, "Translation Incorrectly Set!\nx = %f\ny = %f\n", transform->Translation().x, transform->Translation().y);
			msg.Send();
			assert(false);
		}

		glm::mat3 mtx = transform->Mtx();
		DebugMessage msg_mtx1(Debug::ERROR, "mtx[0][0] = %f\nmtx[0][1] = %f\nmtx[0][2] = %f\n", mtx[0][0], mtx[0][1], mtx[0][2]);
		msg_mtx1.Send();
		DebugMessage msg_mtx2(Debug::ERROR, "mtx[1][0] = %f\nmtx[1][1] = %f\nmtx[1][2] = %f\n", mtx[1][0], mtx[1][1], mtx[1][2]);
		msg_mtx2.Send();
		DebugMessage msg_mtx3(Debug::ERROR, "mtx[2][0] = %f\nmtx[2][1] = %f\nmtx[2][2] = %f\n", mtx[2][0], mtx[2][1], mtx[2][2]);
		msg_mtx3.Send();
		
		delete transform;
	}

	/******************************************************************************/
/*!
  \brief
	Runs tests.

*/
/******************************************************************************/
	void TransformUT::test_Scale()
	{
		glm::vec2 translation(0.f, 0.f);
		glm::vec2 scale(1.f, 1.f);
		Transform* transform = new Transform(translation, scale);

		if (transform->Scale().x != 1.f || transform->Scale().y != 1.f)
		{
			DebugMessage msg(Debug::ERROR, "Scale Incorrectly Initialized!\nx = %f\ny = %f\n", transform->Scale().x, transform->Scale().y);
			msg.Send();
			assert(false);
		}

		scale = glm::vec2(69.f, 420.f);
		transform->Scale(scale);

		if (transform->Scale().x != 69.f || transform->Scale().y != 420.f)
		{
			DebugMessage msg(Debug::ERROR, "Scale Incorrectly Set!\nx = %f\ny = %f\n", transform->Scale().x, transform->Scale().y);
			msg.Send();
			assert(false);
		}

		glm::mat3 mtx = transform->Mtx();
		DebugMessage msg_mtx1(Debug::ERROR, "mtx[0][0] = %f\nmtx[0][1] = %f\nmtx[0][2] = %f\n", mtx[0][0], mtx[0][1], mtx[0][2]);
		msg_mtx1.Send();
		DebugMessage msg_mtx2(Debug::ERROR, "mtx[1][0] = %f\nmtx[1][1] = %f\nmtx[1][2] = %f\n", mtx[1][0], mtx[1][1], mtx[1][2]);
		msg_mtx2.Send();
		DebugMessage msg_mtx3(Debug::ERROR, "mtx[2][0] = %f\nmtx[2][1] = %f\nmtx[2][2] = %f\n", mtx[2][0], mtx[2][1], mtx[2][2]);
		msg_mtx3.Send();

		delete transform;
	}

	/******************************************************************************/
/*!
  \brief
	Runs tests.

*/
/******************************************************************************/
	void TransformUT::test_Rotation()
	{
		glm::vec2 translation(0.f, 0.f);
		glm::vec2 scale(1.f, 1.f);
		float rotation = 1.f;
		Transform* transform = new Transform(translation, scale, rotation);

		if (transform->Rotation() != 1.f)
		{
			DebugMessage msg(Debug::ERROR, "Rotation Incorrectly Initialized!\n r = %f\n", transform->Rotation(), transform->Rotation());
			msg.Send();
			assert(false);
		}

		rotation = 33.f;
		transform->Rotation(rotation);

		if (transform->Rotation() != 33.f)
		{
			DebugMessage msg(Debug::ERROR, "Rotation Incorrectly Set!\nr = %f\n", transform->Rotation());
			msg.Send();
			assert(false);
		}

		glm::mat3 mtx = transform->Mtx();
		DebugMessage msg_mtx1(Debug::ERROR, "mtx[0][0] = %f\nmtx[0][1] = %f\nmtx[0][2] = %f\n", mtx[0][0], mtx[0][1], mtx[0][2]);
		msg_mtx1.Send();
		DebugMessage msg_mtx2(Debug::ERROR, "mtx[1][0] = %f\nmtx[1][1] = %f\nmtx[1][2] = %f\n", mtx[1][0], mtx[1][1], mtx[1][2]);
		msg_mtx2.Send();
		DebugMessage msg_mtx3(Debug::ERROR, "mtx[2][0] = %f\nmtx[2][1] = %f\nmtx[2][2] = %f\n", mtx[2][0], mtx[2][1], mtx[2][2]);
		msg_mtx3.Send();

		delete transform;
	}

}
