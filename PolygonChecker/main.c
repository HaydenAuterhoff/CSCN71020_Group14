#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

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
			//printf_s("! %d\n", triangleSidesPtr[0]);

			if (verify == true){

				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				printf_s("%s\n", result);
			}
			break;

		case 2:
			printf("Hello World");
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
		scanf_s("%f", &triangleSides[i]);
	}
	return triangleSides;
}


	bool verifyTriangle(float side1, float side2, float side3) {

		bool valid;

		if ((side1 + side2) > side3){

			if ((side2 + side3) > side1){

				if ((side1 + side3) > side2){

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
			else{
				printf("Triangle is not valid.\n");
				valid = false;
			}
		}
		else{
			printf("Triangle is not valid.\n");
			valid = false;
		}

		return valid;
	}
 


//commit test