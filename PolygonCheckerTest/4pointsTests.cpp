#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "main.h"
}

namespace RecFourPoints
{
	TEST_CLASS(RecFourPointsBasicInput)
	{
	public:
		TEST_METHOD(T001_makeShape1_1_1_1_2_length1)
		{
			//testing basic input
			float Points[4] = { 1, 1, 1, 2 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.0f, Result);
		}

		TEST_METHOD(T002_makeShape1_1_2_1_1_length1)
		{
			//testing basic input rearranged
			float Points[4] = { 1, 2, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.0f, Result);
		}

		TEST_METHOD(T003_makeShape1_2_1_1_1_length1)
		{
			//testing basic input rearranged
			float Points[4] = { 2, 1, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.0f, Result);
		}

		TEST_METHOD(T004_makeShape1_1_1_2_1_length1)
		{
			//testing basic input rearranged
			float Points[4] = { 1, 1, 2, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.0f, Result);
		}
	};

	TEST_CLASS(RecFourPointsBasicNegativeInput)
	{
	public:
		TEST_METHOD(T001_makeShape1_neg1_1_1_1_length2)
		{
			//testing basic negative input rearranged
			float Points[4] = { -1, 1, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(2.0f, Result);
		}

		TEST_METHOD(T002_makeShape1_1_neg1_1_1_length2)
		{
			//testing basic negative input rearranged
			float Points[4] = { 1, -1, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(2.0f, Result);
		}

		TEST_METHOD(T003_makeShape1_1_1_neg1_1_length_2)
		{
			//testing basic negative input rearranged
			float Points[4] = { 1, 1, -1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(2.0f, Result);
		}

		TEST_METHOD(T004_makeShape1_1_1_1_neg1_length2)
		{
			//testing basic negative input rearranged
			float Points[4] = { 1, 1, 1, -1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(2.0f, Result);
		}
	};

	TEST_CLASS(RecFourPointsComplexInput)
	{
	public:
		TEST_METHOD(T001_makeShape1_2point78_1_1_1_length1point78)
		{
			//testing complex input rearranged
			float Points[4] = { 2.78, 1, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.78f, Result);
		}

		TEST_METHOD(T002_makeShape1_1_2point78_1_1_length1point78)
		{
			//testing complex input rearranged
			float Points[4] = { 1, 2.78, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.78f, Result);
		}

		TEST_METHOD(T003_makeShape1_1_1_2point78_1_length1point78)
		{
			//testing complex input rearranged
			float Points[4] = { 1, 1, 2.78, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.78f, Result);
		}

		TEST_METHOD(T004_makeShape1_1_1_1_2point78_length1point78)
		{
			//testing complex input rearranged
			float Points[4] = { 1, 1, 1, 2.78 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(1.78f, Result);
		}
	};

	TEST_CLASS(RecFourPointsComplexNegativeInput)
	{
	public:
		TEST_METHOD(T004_makeShape1_neg2point78_1_1_1_length3point78)
		{
			//testing negative complex input rearranged
			float Points[4] = { -2.78, 1, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(3.78f, Result);
		}

		TEST_METHOD(T002_makeShape1_1_neg2point78_1_1_length3point78)
		{
			//testing negative complex input rearranged
			float Points[4] = { 1, -2.78, 1, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(3.78f, Result);
		}

		TEST_METHOD(T003_makeShape1_1_1_neg2point78_1_length3point78)
		{
			//testing negative complex input rearranged
			float Points[4] = { 1, 1, -2.78, 1 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(3.78f, Result);
		}

		TEST_METHOD(T004_makeShape1_1_1_1_neg2point78_length3point78)
		{
			//testing negative complex input rearranged
			float Points[4] = { 1, 1, 1, -2.78 };

			float Result = makeShape1(Points[0], Points[1], Points[2], Points[3]);

			Assert::AreEqual(3.78f, Result);
		}
	};

	TEST_CLASS(RecPerimeterBasicInput)
	{
	public:
		TEST_METHOD(T001_rectanglePerimeter_1_1_1_1_expect4)
		{
			//testing basic input rearranged
			float Sides[4] = { 1, 1, 1, 1 };

			float Result = rectanglePerimeter(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::AreEqual(4.0f, Result);
		}

		TEST_METHOD(T002_rectanglePerimeter_1_2point5_1point1_2point5_expect7)
		{
			//testing basic input rearranged
			float Sides[4] = { 1, 2.5, 1.1, 2.5 };

			float Result = rectanglePerimeter(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::AreEqual(7.1f, Result);
		}
	};

	TEST_CLASS(RecAreaBasicInput)
	{
	public:
		TEST_METHOD(T001_rectangleArea_1_1_expect1)
		{
			//testing basic input rearranged
			float Sides[2] = { 1, 1 };

			float Result = rectangleArea(Sides[0], Sides[1]);

			Assert::AreEqual(1.0f, Result);
		}

		TEST_METHOD(T002_rectangleArea_5_6_expect1)
		{
			//testing basic input rearranged
			float Sides[2] = { 5, 6 };

			float Result = rectangleArea(Sides[0], Sides[1]);

			Assert::AreEqual(30.0f, Result);
		}

		TEST_METHOD(T003_rectangleArea_5point6_6_expect1)
		{
			//testing basic input rearranged
			float Sides[2] = { 5.6, 6 };

			float Result = rectangleArea(Sides[0], Sides[1]);

			Assert::AreEqual(33.6f, Result);
		}
	};

	TEST_CLASS(verifyRecBasicInput)
	{
	public:
		TEST_METHOD(T001_verifyRectangle_1_1_1_1_expect_true)
		{
			//testing basic input rearranged
			float Sides[4] = { 1, 1, 1, 1 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsTrue;
		}

		TEST_METHOD(T002_verifyRectangle_2_4_2_4_expect_true)
		{
			//testing basic input rearranged
			float Sides[4] = { 2, 4, 2, 4 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsTrue;
		}

		TEST_METHOD(T003_verifyRectangle_4_2_4_2_expect_true)
		{
			//testing basic input rearranged
			float Sides[4] = { 4, 2, 4, 2 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsTrue;
		}

		TEST_METHOD(T003_verifyRectangle_6_2_4_2_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { 6, 2, 4, 2 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsFalse;
		}
	};

	TEST_CLASS(verifyRecNegBasicInput)
	{
	public:
		TEST_METHOD(T001_verifyRectangle_neg1_1_neg1_1_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { -1, 1, -1, 1 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsFalse;
		}

		TEST_METHOD(T002_verifyRectangle_neg2_4_neg2_4_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { -2, 4, -2, 4 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsFalse;
		}

		TEST_METHOD(T003_verifyRectangle_neg4_2_neg4_2_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { -4, 2, -4, 2 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsFalse;
		}

		TEST_METHOD(T003_verifyRectangle_neg6_2_4_2_expect_true)
		{
			//testing basic input rearranged
			float Sides[4] = { -6, 2, 4, 2 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsFalse;
		}
	};

	TEST_CLASS(verifyRecComplexInput)
	{
	public:
		TEST_METHOD(T001_verifyRectangle_1point5_1_1point5_1_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { 1.5, 1, 1.5, 1 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsTrue;
		}

		TEST_METHOD(T002_verifyRectangle_2point5_4_2point5_4_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { 2.5, 4, 2.5, 4 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsTrue;
		}

		TEST_METHOD(T003_verifyRectangle_4_2point5_4_2point5_expect_true)
		{
			//testing basic negative input rearranged
			float Sides[4] = { 4, 2.5, 4, 2.5 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsTrue;
		}

		TEST_METHOD(T003_verifyRectangle_6point5_2_4_2_expect_true)
		{
			//testing basic input rearranged
			float Sides[4] = { 6.5, 2, 4, 2 };

			verifyRectangle(Sides[0], Sides[1], Sides[2], Sides[3]);

			Assert::IsFalse;
		}
	};
}