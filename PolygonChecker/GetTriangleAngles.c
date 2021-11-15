#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "GetTriangleAngles.h"

float* getTriangleAnglesT(float side1, float side2, float side3)
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