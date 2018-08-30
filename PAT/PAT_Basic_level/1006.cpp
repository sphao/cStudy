/*
* @Author: sphao
* @Date:   2018-08-25 18:46:12
* @Last Modified by:   sphao
* @Last Modified time: 2018-08-25 18:59:17
*/
/*
1006 换个格式输出整数 (15)（15 分）
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（&lt10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（&lt1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：

234
输出样例1：

BBSSS1234
输入样例2：

23
输出样例2：

SS123
 */

#include <cstdio>

int main(void)
{
	int n;
	scanf("%d", &n);
	int b;
	b = n/100;
	int s;
	s = (n - b*100)/10;
	int g;
	g = n%10;
	for(int i = 0; i < b; i++)
	{
		printf("B");
	}
	for(int i = 0; i < s; i++)
	{
		printf("S");
	}
	for(int i = 1; i <= g; i++)
	{
		printf("%d", i);
	}
	return 0;
}