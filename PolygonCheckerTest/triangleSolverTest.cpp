#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "main.h"
}

namespace TriangleSolver
{
	TEST_CLASS(TriangleSolver)
	{
	public:

		TEST_METHOD(T001_analyzeTriangle_Scalene_true)
		{

			int side1;

			int side2;

			int side3;

			char* result;

			side1 = 3;

			side2 = 4;

			side3 = 5;

			result = analyzeTriangle(side1, side2, side3);


			Assert::AreEqual("Scalene triangle", result);


		}


		TEST_METHOD(T002_analyzeTriangle_Scalene_false)
		{

			int side1;

			int side2;

			int side3;

			char* result;

			side1 = 3;

			side2 = 5;

			side3 = 5;

			result = analyzeTriangle(side1, side2, side3);


			Assert::AreNotEqual("Scalene triangle", result);

		}

		TEST_METHOD(T003_analyzeTriangle_Isosceles_true)
		{

			int side1;

			int side2;

			int side3;

			char* result;

			side1 = 3;

			side2 = 4;

			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Isosceles triangle", result);

		}


		TEST_METHOD(T004_analyzeTriangle_Isosceles_false)
		{

			int side1;

			int side2;

			int side3;

			char* result;

			side1 = 3;

			side2 = 3;

			side3 = 3;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Isosceles triangle", result);

		}


		TEST_METHOD(T005_analyzeTriangle_Equilateral_true)
		{

			int side1;

			int side2;

			int side3;

			char* result;

			side1 = 3;

			side2 = 3;

			side3 = 3;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Equilateral triangle", result);

		}

		TEST_METHOD(T006_analyzeTriangle_Equilateral_false)
		{

			int side1;

			int side2;

			int side3;

			char* result;



			side1 = 3;

			side2 = 3;

			side3 = 4;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Equilateral triangle", result);

		}


		TEST_METHOD(T007_analyzeTriangle_notTriangle_true)
		{

			int side1;

			int side2;

			int side3;

			char* result;

			side1 = -1;

			side2 = 3;

			side3 = 3;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Not a triangle", result);

		}

		TEST_METHOD(T008_analyzeTriangle_notTriangle_false)
		{

			int side1;

			int side2;

			int side3;

			char* result;



			side1 = 3;

			side2 = 3;

			side3 = 3;

			result = analyzeTriangle(side1, side2, side3);

			Assert::AreNotEqual("Not a triangle", result);

		}

		TEST_METHOD(T009_verifyTriangle_side1Negative_false) {


			float side1;

			float side2;

			float side3;

			side1 = -3;

			side2 = 3;

			side3 = 3;

			bool valid;


			valid = verifyTriangle(side1, side2, side3);

			Assert::IsFalse(valid);


		}

		TEST_METHOD(T010_verifyTriangle_side1TooBig_false) {


			float side1;

			float side2;

			float side3;

			side1 = 30;

			side2 = 3;

			side3 = 3;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsFalse(valid);


		}

		TEST_METHOD(T011_verifyTriangle_side2Negative_false) {


			float side1;

			float side2;

			float side3;

			side1 = 3;

			side2 = -3;

			side3 = 3;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsFalse(valid);


		}

		TEST_METHOD(T012_verifyTriangle_side2TooBig_false) {


			float side1;

			float side2;

			float side3;

			side1 = 3;

			side2 = 30;

			side3 = 3;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsFalse(valid);


		}

		TEST_METHOD(T013_verifyTriangle_side3Negative_false) {


			float side1;

			float side2;

			float side3;

			side1 = 3;

			side2 = 3;

			side3 = -3;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsFalse(valid);


		}

		TEST_METHOD(T014_verifyTriangle_side3TooBig_false) {


			float side1;

			float side2;

			float side3;

			side1 = 3;

			side2 = 3;

			side3 = -3;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsFalse(valid);

		}

		TEST_METHOD(T015_verifyTriangle_vaildScalene_true) {


			float side1;

			float side2;

			float side3;

			side1 = 3;

			side2 = 4;

			side3 = 5;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsTrue(valid);

		}

		TEST_METHOD(T016_verifyTriangle_vaildIsosceles_true) {


			float side1;

			float side2;

			float side3;

			side1 = 3;

			side2 = 5;

			side3 = 5;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsTrue(valid);

		}

		TEST_METHOD(T017_verifyTriangle_vaildEquilateral_true) {


			float side1;

			float side2;

			float side3;

			side1 = 5;

			side2 = 5;

			side3 = 5;

			bool valid;

			valid = verifyTriangle(side1, side2, side3);

			Assert::IsTrue(valid);

		}


	};

}