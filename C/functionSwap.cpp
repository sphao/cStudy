/*
* @Author: sphao
* @Date:   2018-05-23 16:13:37
* @Last Modified by:   sphao
* @Last Modified time: 2018-05-23 16:13:48
*/
#include <cstdio>

void swap(int * a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	int a = 5;
	int b = 8;
	printf("a= %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a= %d, b = %d\n", a, b);
	return 0;
}