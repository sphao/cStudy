/*
* @Author: sphao
* @Date:   2018-08-31 17:28:23
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-01 19:14:14
*/

/*
1009 说反话（20 分）
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
 */

#include <cstdio>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	char a[80];
	//将输入存储进数组(scanf无法读入空格,所以使用getchar)
	int i = 0;
	while((a[i] = getchar())!='\n')
	{
		i++;
	}
	a[i] = '\0';	//输出时不输出换行符,以\0作替换
	for(int j = i-1; j > 0; j--)
	{
		if(a[j] == ' ')
		{
			printf("%s ", &a[j+1]);
			a[j] = '\0';
		}
	}
	printf("%s", &a[0]);	//第一个输入前没有空格,循环中未能输出,直接补上即可
	return 0;
}