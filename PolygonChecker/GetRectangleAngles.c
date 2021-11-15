/*
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "GetRectangleAngles.h"

float* getRectangleAngles(float side1, float side2, float side3, float side4, float 5)
{
	float pi;
	float s;
	float R;
	float area;
	float angle1;
	float angle2;
	float angle3;
	float angle4;
	pi = acos(-1);

	s = (side1 + side2 + side3 + side4) / 2;
	area = sqrt(s * (s - side1) * (s - side2) * (s - side3) * (s - side4));

	R = (side1 * side2 * side3 * side4 ) / (4 * area);

	angle1 = (360 / pi) * asin(side1 / (2 * R));
	angle2 = (360 / pi) * asin(side2 / (2 * R));
	angle3 = (360 / pi) * asin(side3 / (2 * R));
	angle4 = (360 / pi) * asin(side4 / (2 * R));

	printf("Angles: %6.2f %6.2f %6.2f %6.2f\n", angle1, angle2, angle3, angle4);

	return 0;
}
*/