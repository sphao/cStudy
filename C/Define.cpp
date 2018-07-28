/*
* @Author: sphao
* @Date:   2018-04-18 10:22:24
* @Last Modified by:   sphao
* @Last Modified time: 2018-04-18 10:28:52
*/
#include <cstdio>
#define PI 3.14159

int main(void)
{
	float area, circum, radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f",&radius);
	area = PI * radius *radius;
	circum = 2.0 * PI * radius;
	printf("Your basic pizza parameters are ad fallows:\n");
	printf("circumference = %1.2f, area = %1.2f\n", circum, area);
}