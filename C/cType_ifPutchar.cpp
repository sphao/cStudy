/*
* @Author: sphao
* @Date:   2018-04-25 14:29:05
* @Last Modified by:   sphao
* @Last Modified time: 2018-04-29 23:52:54
*/
#include <cstdio>
#include <cctype>						//处理字符的函数头文件

int main(int argc, char const *argv[])
{ 
	char ch;
	while((ch = getchar()) != '\n')		//C语言中常见的写法，应熟悉
	{
	
		if(isalpha(ch))					//判断是否是字母

			putchar(ch+1);
		else
			putchar(ch);
	}
	putchar('\n');
	return 0;
}