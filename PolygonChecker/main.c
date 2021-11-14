#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "main.h"
#include "triangleSolver.h"
#include "GetTriangleAngles.h"

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

			//printf("%f %f %f", triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

			bool verify = verifyTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

			if (verify == true) {

				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				printf_s("%s\n", result);

				int angles = getTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
			break;

		case 2:
			
			printf("Rectangle Selected. \n");
			float rectanglePoints[8] = { 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f };
			float* rectanglePointsPtr = getRectanglePoints(rectanglePoints);


			//int length1 = makeShape(rectanglePointsPtr1[0], rectanglePointsPtr1[1], rectanglePointsPtr2[0], rectanglePointsPtr2[1]);
			//printf("%d", length1);
			/*
			float rectangleSidesPtr2 = makeShape(rectanglePointsPtr1, rectanglePointsPtr3);
			float rectangleSidesPtr3 = makeShape(rectanglePointsPtr1, rectanglePointsPtr4);
			float rectangleSidesPtr4 = makeShape(rectanglePointsPtr2, rectanglePointsPtr3);
			float rectangleSidesPtr5 = makeShape(rectanglePointsPtr2, rectanglePointsPtr4);
			float rectangleSidesPtr6 = makeShape(rectanglePointsPtr3, rectanglePointsPtr4);
			*/
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
	for (int i = 0.f; i < 4.f; i++)
	{
		int k = 0;
		printf("Enter point %d: ", i+1);
		for (int j = 0.f; j < 2.f; j++)
		{
			scanf_s("%f", &rectangleSides[i+k+j]);
		}
		k++;
	}
	return rectangleSides;
}

int* makeShape(float Point1[], float Point2[])
{
	int sideLength;
	float xPoint = Point1[0] - Point2[0];
	float yPoint = Point1[1] - Point2[1];

	sideLength = sqrt((xPoint * xPoint) + (yPoint * yPoint));

	return sideLength;
}

bool verifyTriangle(float side1, float side2, float side3) {

	bool valid;

	if ((side1 + side2) > side3) {

		if ((side2 + side3) > side1) {

			if ((side1 + side3) > side2) 
			{
				printf("Triangle is valid.\n");
				valid = true;
				}
				else{
				

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
