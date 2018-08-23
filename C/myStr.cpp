/*
* @Author: sphao
* @Date:   2018-08-15 08:43:21
* @Last Modified by:   sphao
* @Last Modified time: 2018-08-15 10:38:09
*/

#include <cstdio>

int myStrlen(char * src);
char * myStrcat(char * dest, char * src);
char * myStrcpy(char * dest, char * src);

int myStrlen(char * src)
{
	int len = 0;
	while(*src ++)
	{
		len ++;
	}
	return len;
}
char * myStrcat(char * dest, char * src)
{
	char * setDest;
	setDest = dest;
	for(; *dest; dest++);
	for(; *dest = *src; dest++, src++);
	return setDest;
}
char * myStrcpy(char * dest, char * src)
{
	char * setDest;
	setDest = dest;
	while(*dest++ = *src++);
	return setDest;
}

int main(int argc, char const *argv[])
{
	char str[] = "hello world!";
	char str2[] = "something for nothing.";
	printf("%d\n", myStrlen(str));
	printf("%s\n", myStrcat(str, str2));
	printf("%s\n", myStrcpy(str, str2));
	return 0;
}