#include<cstdio>
#define PRAISE "You are an extraordinary being."

int main(int argc, char const *argv[])
{
	char name[40];
	printf("What is your name?\n");
	scanf("%s",name);
	printf("Hello, %s.%s\n", name, PRAISE);
	return 0;
}

//scanf 在读取到第一个空格、制表符、换行符的时候就不再读取输入。