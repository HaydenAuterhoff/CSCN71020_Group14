#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "main.h"

#define RAD_2_DEG 57.2958

float getTriangleAngles(float side1, float side2, float side3)
{

	// Flavius' version v2
	/*float pi, s, area, R;

	pi = acos(-1);

	s = (side1 + side2 + side3) / 2;
	area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

	R = (side1 * side2 * side3) / (4 * area);

	float angles[3] = { 0.f, 0.f, 0.f };
	angles[0] = (180 / pi) * asin(side1 / (2 * R));
	angles[1] = (180 / pi) * asin(side2 / (2 * R));
	angles[2] = (180 - angles[0] - angles[1]);

	printf("Angles: %6.2f %6.2f %6.2f\n", angles[0], angles[1], angles[2]);

	float sum = angles[0] + angles[1] + angles[2];

	return sum;
	*/

	// Hayden's version
	//      A     =             cos-1(       b^2      +       c^2       -       a^2      ) / (          2bc     )
	float angles1 = RAD_2_DEG * acos(((side2 * side2) + (side3 * side3) - (side1 * side1)) / (2 * side2 * side3));
	float angles2 = RAD_2_DEG * acos(((side1 * side1) + (side3 * side3) - (side2 * side2)) / (2 * side1 * side3));
	float angles3 = RAD_2_DEG * acos(((side1 * side1) + (side2 * side2) - (side3 * side3)) / (2 * side2 * side1));

	printf("Angles: %6.2f %6.2f %6.2f\n", angles1, angles2, angles3);

	int sum = angles1 + angles2 + angles3;  //we don't know why this is an int but it works

	return sum;

}
