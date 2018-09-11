/*
* @Author: sphao
* @Date:   2018-09-11 21:46:16
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-11 23:10:37
*/

/*
1021 个位数统计（15 分）
​​请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

输入样例：
100311
输出样例：
0:2
1:3
3:1
 */

#include <cstdio>

int main(int argc, char const *argv[])
{
	int a[10] = {0};
	char c = 0;
	scanf("%c", &c);
	while(c != '\n')
	{
		a[c - '0'] ++;
		scanf("%c", &c);
	}
	for(int i = 0; i < 10; i++)
	{
		if(a[i] != 0)
		{
			printf("%d:%d\n", i, a[i]);
		}
	}
	return 0;
}