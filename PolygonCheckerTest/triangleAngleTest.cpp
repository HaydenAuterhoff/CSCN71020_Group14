#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "main.h"
}

namespace TriangleAngle
{
	TEST_CLASS(TriangleAngle)
	{
	public:
		// Tests that the angles of the triangle form 180* giving equilateral sides
		TEST_METHOD(T001_TriangleAngleTest_EquilateralTriangle_true)
		{
			float side1 = 5;
			float side2 = 5;
			float side3 = 5;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreEqual(sum, result);
		}

		// Tests that the angles of the triangle form 180* giving isosceles sides
		TEST_METHOD(T002_TriangleAngleTest_IsoscelesTriangle_true)
		{
			float side1 = 4;
			float side2 = 4;
			float side3 = 5;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreEqual(sum, result);
		}

		// Tests that the angles of the triangle form 180* giving scalene sides
		TEST_METHOD(T003_TriangleAngleTest_ScaleneTriangle_true)
		{
			float side1 = 5;
			float side2 = 10;
			float side3 = 11;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreEqual(sum, result);
		}

		// Tests that the angles of the triangle do not form 180* giving equilateral sides
		TEST_METHOD(T004_TriangleAngleTest_EquilateralTriangle_false)
		{
			float side1 = 5;
			float side2 = 5;
			float side3 = 25; // 5*5

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreNotEqual(sum, result);
		}

		// Tests that the angles of the triangle do not form 180* giving equilateral sides
		TEST_METHOD(T005_TriangleAngleTest_IsoscelesTriangle_false)
		{
			float side1 = 4;
			float side2 = 4;
			float side3 = 10;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreNotEqual(sum, result);
		}

		// Tests that the angles of the triangle do not form 180* giving equilateral sides
		TEST_METHOD(T006_TriangleAngleTest_ScaleneTriangle_false)
		{
			float side1 = 1;
			float side2 = 10;
			float side3 = 15;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreNotEqual(sum, result);
		}

		// Tests that the angles of the triangle do not form 180* giving a negative side
		TEST_METHOD(T007_TriangleAngleTest_NegativeIntegerTriangle_true)
		{
			float side1 = -1;
			float side2 = 10;
			float side3 = 15;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreNotEqual(sum, result);
		}

		// Tests that the angles of the triangle form 180* giving a decimal side
		TEST_METHOD(T008_TriangleAngleTest_PositiveDecimalTriangle_true)
		{
			float side1 = 2.5;
			float side2 = 3;
			float side3 = 5;

			float result = getTriangleAngles(side1, side2, side3);

			float sum = 180.f;

			Assert::AreEqual(sum, result);
		}
	};
}