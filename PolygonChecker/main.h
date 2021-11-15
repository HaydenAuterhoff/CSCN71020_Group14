#pragma once
void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
int* getRectanglePoints(int*);
bool verifyTriangle(float side1, float side2, float side3);
//float* getTriangleAngles(float, float, float);
float* makeShape1(float, float, float, float);
float* makeShape2(float, float, float, float);
float* makeShape3(float, float, float, float);
float* makeShape4(float, float, float, float);
int rectanglePerimeter(int, int, int, int);
int rectangleArea(int, int);
bool verifyRectangle(int, int, int, int);
