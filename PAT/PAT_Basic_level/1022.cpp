/*
* @Author: sphao
* @Date:   2018-09-12 20:28:16
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-12 20:57:49
*/

/*
1022 D进制的A+B （20 分）
输入两个非负 10 进制整数 A 和 B (≤2^30−1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
 */

#include <cstdio>

int main(int argc, char const *argv[])
{
	unsigned int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	unsigned int c = a + b;
	int e[32] = {0};
	int len = 0;
	while(c >= d)
	{
		e[len++] = c % d;		//取余
		c /= d;			//除权
	}
	e[len] = c;			//补上最高位并补上c最初就小于d的情况
	//倒排
	for(int i = len; i >= 0; i--)
	{
		printf("%d", e[i]);
	}
	printf("\n");
	return 0;
}