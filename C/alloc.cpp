/*
* @Author: sphao
* @Date:   2018-08-23 10:40:10
* @Last Modified by:   sphao
* @Last Modified time: 2018-08-23 18:17:39
*/

#include <cstdio>
#include <cstdlib>
#include <string.h>

int main(int argc, char const *argv[])
{
	//calloc: int *array = (int *)calloc(10,sizeof(int));
	char *p = (char *)malloc(5);	//malloc
	strcpy(p,"hi");
	printf("%s\n", p);
	char * q = (char *)realloc(p, 10);	//p 和 q有可能相等(连续空间足够)，有可能不等(连续空间不足，开辟新空间并将旧空间内容拷贝过来并释放)。
	printf("%s\n", p);
	free(q);
	q = NULL;
	return 0;
}