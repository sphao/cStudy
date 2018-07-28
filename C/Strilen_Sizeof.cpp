#include <cstdio>
#include <cstring>
#define PRAISE "You are an extraordinary being."

int main(int argc, char const *argv[])
{
	char name[40];
	printf("What's your name?\n");
	scanf("%s",name);
	printf("Hello, %s.%s\n", name, PRAISE);
	printf("Your name of %zd letters occupies %zd memory cells.\n",
		strlen(name), sizeof name);		//sizeof 运算对象是类型，必须加圆括号；运算对象是特定量，则可省略。但是建议全都不省略。
	printf("The Phrase of praise has %zd letters ", strlen(PRAISE));
	printf("and occupies %zd memory cells.\n",sizeof(PRAISE));
	return 0;
}