#pragma once
void printWelcome();
int printShapeMenu();

int* getTriangleSides(int* triangleSides);
bool verifyTriangle(float side1, float side2, float side3);
char* analyzeTriangle(int side1, int side2, int side3);
float getTriangleAngles(float, float, float);


int* getRectanglePoints(int*);
float makeShape1(float, float, float, float);
float makeShape2(float, float, float, float);
float makeShape3(float, float, float, float);
float makeShape4(float, float, float, float);
bool verifyRectangle(int, int, int, int);
float rectanglePerimeter(float, float, float, float);
float rectangleArea(float, float);
