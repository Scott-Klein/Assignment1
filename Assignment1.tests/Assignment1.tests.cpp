#include "pch.h"
#include "CppUnitTest.h"
#include "../Assignment1/State.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment1tests
{
	TEST_CLASS(Assignment1tests)
	{
	public:
		/*
		Task  1: Create  a  class,  named State,  with  related  data  members  to  store  a 
		game state (an arrayof nine integers,a 3*3 two-dimensional array of integers, an array 
		of three vectors, an array of three stacks, or any other data types you prefer to use) 
		and necessary methodsfor variable initialisation, data input andgame boarddisplay.
		*/
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
			Assert::AreNotEqual(4, 1);
		}

		TEST_METHOD(ShouldFail)
		{
			Assert::IsTrue(false);
		}
	};
}
