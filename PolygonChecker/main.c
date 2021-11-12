#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "main.h"
#include "triangleSolver.h"
#include "GetTriangleAngles.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:

			printf_s("Triangle selected.\n");
			float triangleSides[3] = { 0.f, 0.f, 0.f };
			float* triangleSidesPtr = getTriangleSides(triangleSides);

			bool verify = verifyTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

			if (verify == true) {

				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				printf_s("%s\n", result);

				int angles = getTriangleAnglesT(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
			break;

		case 2:
			printf("Rectangle Selected. \n");
			float rectanglePoints[8] = { 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f };
			float* rectanglePointsPtr1 = getRectanglePoints(rectanglePoints);
			float* rectanglePointsPtr2 = getRectanglePoints(rectanglePoints);
			float* rectanglePointsPtr3 = getRectanglePoints(rectanglePoints);
			float* rectanglePointsPtr4 = getRectanglePoints(rectanglePoints);

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


	void printWelcome() {
		printf_s("\n");
		printf_s(" **********************\n");
		printf_s("**     Welcome to     **\n");
		printf_s("**   Polygon Checker  **\n");
		printf_s(" **********************\n");
	}

	int printShapeMenu() {
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
	for (int i = 0.f; i < 2.f; i++) 
	{
		printf_s("Enter point %d (x,y): \n", i);
		scanf_s("%f", &rectangleSides[i]);
	}
}

	bool verifyTriangle(float side1, float side2, float side3) {

		bool valid;

		if ((side1 + side2) > side3) {

			if ((side2 + side3) > side1) {

				if ((side1 + side3) > side2) {

					/*
					 * If side1 + side2 > side3 and
					 *    side2 + side3 > side1 and
					 *    side1 + side3 > side2 then
					 * the triangle is valid.
					 */
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

	float* getTriangleAngles(float side1, float side2, float side3)
	{
		float pi, s, area, R;
		float angle1, angle2, angle3;
		pi = acos(-1);

		s = (side1 + side2 + side3) / 2;
		area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

		R = (side1 * side2 * side3) / (4 * area);

		angle1 = (180 / pi) * asin(side1 / (2 * R));
		angle2 = (180 / pi) * asin(side2 / (2 * R));
		angle3 = (180 / pi) * asin(side3 / (2 * R));

		printf("Angles: %6.2f %6.2f %6.2f\n", angle1, angle2, angle3);

		return 0;
	}