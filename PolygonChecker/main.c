#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "main.h"
//#include "triangleSolver.h"
//#include "GetTriangleAngles.h"
//#include "GetRectangleAngles.h"

int side = 0;

int main()
{

	bool continueProgram = true;
	while (continueProgram)
	{
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:

			printf_s("Triangle selected.\n");
			float triangleSides[3] = { 0.f, 0.f, 0.f };
			float* triangleSidesPtr = getTriangleSides(triangleSides);

			//Call Function to verify shape is a triangle using the three side lengths
			bool verifyTri = verifyTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

			if (verifyTri == true)
			{
				//Call Function to analyze Triangle to determine the type of triangle
				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				printf_s("%s\n", result);

				//Call Function to calculate the angles of the triangle
				int angles = getTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
			break;

		case 2:

			printf("Rectangle Selected. \n");
			float rectanglePoints[8] = { 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f };
			float* rectanglePointsPtr = getRectanglePoints(rectanglePoints);

			//Call Function to determine the length between each point (In user-input order)
			int sideLength1 = makeShape1(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2], rectanglePointsPtr[3]); //Length of Point 1 --> Point 2
			int sideLength2 = makeShape2(rectanglePointsPtr[2], rectanglePointsPtr[3], rectanglePointsPtr[4], rectanglePointsPtr[5]); //Length of Point 2 --> Point 3
			int sideLength3 = makeShape3(rectanglePointsPtr[4], rectanglePointsPtr[5], rectanglePointsPtr[6], rectanglePointsPtr[7]); //Length of Point 3 --> Point 4
			int sideLength4 = makeShape4(rectanglePointsPtr[6], rectanglePointsPtr[7], rectanglePointsPtr[0], rectanglePointsPtr[1]); //Length of Point 4 --> Point 1

			//Call Function to verify shape is a rectangle using Pythagorean Theorem
			bool verifyRec = verifyRectangle(sideLength1, sideLength2, sideLength3, sideLength4);

			if (verifyRec == true)
			{
				//Call Function to determine the perimeter of the shape
				rectanglePerimeter(sideLength1, sideLength2, sideLength3, sideLength4);
				rectangleArea(sideLength1, sideLength2); //Call Function to determine the area of the rectangle
			}
			else
			{
				rectanglePerimeter(sideLength1, sideLength2, sideLength3, sideLength4);
			}

			break;

		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}


void printWelcome()
{
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu()
{
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0.f; i < 3.f; i++)
	{
		if (scanf_s("%f", &triangleSides[i]) != 1)
		{
			printf("Invalid Input!\n");
			exit(1);
		}
	}
	return triangleSides;
}

int* getRectanglePoints(int* rectangleSides)
{
	int k = 0;
	for (int i = 0.f; i < 4.f; i++)
	{
		printf("Enter point %d (x y): ", i + 1);
		for (int j = 0.f; j < 2.f; j++)
		{
			scanf_s("%f", &rectangleSides[i + k + j]);
		}
		k++;
	}
	return rectangleSides;
}

float* makeShape1(float point1x, float point1y, float point2x, float point2y)
{
	int sideLength1 = sqrt((point1x - point2x) * (point1x - point2x) + ((point1y - point2y) * (point1y - point2y)));

	return sideLength1;
}

float* makeShape2(float point1x, float point1y, float point4x, float point4y)
{
	int sideLength2 = sqrt((point4x - point1x) * (point4x - point1x) + ((point4y - point1y) * (point4y - point1y)));

	return sideLength2;
}

float* makeShape3(float point2x, float point2y, float point3x, float point3y)
{
	int sideLength3 = sqrt((point2x - point3x) * (point2x - point3x) + ((point2y - point3y) * (point2y - point3y)));

	return sideLength3;
}

float* makeShape4(float point3x, float point3y, float point4x, float point4y)
{
	int sideLength4 = sqrt((point3x - point4x) * (point3x - point4x) + ((point3y - point4y) * (point3y - point4y)));

	return sideLength4;
}
// The sum of two sides needs to be greater than the length of the third side (Ex. 3 4 5 is valid, but 1 1 15 is not valid)
bool verifyTriangle(float side1, float side2, float side3) {

	bool valid;

	if ((side1 + side2) > side3) {

		if ((side2 + side3) > side1) {

			if ((side1 + side3) > side2)
			{
				printf("Triangle is valid.\n");
				valid = true;
			}
			else {


				printf("Triangle is not valid.\n");
				valid = false;
			}
		}

		else {

			printf("Triangle is not valid.\n");
			valid = false;
		}
	}

	else {

		printf("Triangle is not valid.\n");
		valid = false;
	}

		return valid;
	}

// these two functions do the calculations for determining the perimeter and area of a rectangle
int rectanglePerimeter(int sideLength1, int sideLength2, int sideLength3, int sideLength4)
{
	int p = sideLength1 + sideLength2 + sideLength3 + sideLength4;
	printf("Perimeter of the shape = %i units\n", p);
}

int rectangleArea(int sideLength1, int sideLength2)
{
	int a = sideLength1 * sideLength2;
	printf("Area of the rectangle = %i units squared", a);
}

bool verifyRectangle(int side1, int side2, int side3, int side4) //Verify the rectangle using Pythagorean Theorem (Two right-angled triangles)
{
	if (sqrt((side1 * side1) + (side2 * side2)) == (sqrt((side3 * side3) + (side4 * side4))))
	{
		return true;
	}
}