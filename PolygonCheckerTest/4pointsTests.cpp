#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "main.h"
}

namespace RecFourPoints
{
	TEST_CLASS(RecFourPoints) 
	{
	public:

		// Serial#_functionName_Input_ExpectedResult
		TEST_METHOD(FourTest001_Length_1) 
		{
			float Points[4] = { 1, 1, 1, 2 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			float Expected = 1.0f;

			Assert::AreEqual(Expected, Result);

		}
	};
}