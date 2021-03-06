/*
* @Author: sphao
* @Date:   2018-04-19 14:28:09
* @Last Modified by:   sphao
* @Last Modified time: 2018-04-19 14:39:06
*/
#include <cstdio>

int main(int argc, char const *argv[])
{
	int a = 123;
	float b = 123.45;
	printf("*************************************\n");
	printf("int a = 123; float b = 123.45\n");
	printf("int类型\n");
	printf("%%d = *%d*\n", a);
	printf("%%2d = *%2d*\n", a);
	printf("%%10d = *%10d*\n", a);
	printf("%%-10d = *%-10d*\n", a);
	printf("%%+10d = *%+10d*\n", a);
	printf("*************************************\n");
	printf("float类型\n");
	printf("%%f = *%f*\n", b);
	printf("%%e = *%e*\n", b);
	printf("%%4.2f = *%4.2f*\n", b);
	printf("%%3.1f = *%3.1f*\n", b);
	printf("%%10.3f = *%10.3f*\n", b);
	printf("%%10.3E = *%10.3E*\n", b);
	printf("%%+4.2f = *%+4.2f*\n", b);
	printf("%%010.2f = *%010.2f*\n", b);

	return 0;
}


/*
	输出结果：
*********************************************************
*************************************
int a = 123; float b = 123.45
int类型
%d = *123*
%2d = *123*
%10d = *       123*
%-10d = *123       *
%+10d = *      +123*
*************************************
float类型
%f = *123.449997*
%e = *1.234500e+02*
%4.2f = *123.45*
%3.1f = *123.4*
%10.3f = *   123.450*
%10.3E = * 1.234E+02*
%+4.2f = *+123.45*
%010.2f = *0000123.45*
*********************************************************
*/