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

			int rectangle = makeShape(rectanglePointsPtr[0], rectanglePointsPtr[1], rectanglePointsPtr[2], rectanglePointsPtr[3], rectanglePointsPtr[4], rectanglePointsPtr[5], rectanglePointsPtr[6], rectanglePointsPtr[7]);
			//int length1 = makeShape(rectanglePointsPtr1[0], rectanglePointsPtr1[1], rectanglePointsPtr2[0], rectanglePointsPtr2[1]);
			//printf("%d", length1);

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
		printf("Enter point %d: ", i+1);
		for (int j = 0.f; j < 2.f; j++)
		{
			scanf_s("%f", &rectangleSides[i+k+j]);
		}
		k++;
	}
	return rectangleSides;
}

float* makeShape(float point1x, float point1y, float point2x, float point2y, float point3x, float point3y, float point4x, float point4y)
{
	int sideLength1 = sqrt((point1x - point2x) * (point1x - point2x) + ((point1y - point2y) * (point1y - point2y)));
	printf("%d", sideLength1);

	//return sideLength;
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
