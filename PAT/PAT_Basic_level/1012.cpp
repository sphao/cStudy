/*
* @Author: sphao
* @Date:   2018-09-02 16:29:19
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-02 18:09:15
*/

/*
1012 数字分类（20 分）
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A​1=能被5整除的数字中所有偶数的和；
A​2=将被5除后余1的数字按给出顺序进行交错求和，即计算n​1−n2+n​3−n​4⋯；
A​3=被5除后余2的数字的个数；
A​4=被5除后余3的数字的平均数，精确到小数点后1位；
A​5=被5除后余4的数字中最大数字。
输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A​5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
 */

#include <cstdio>

int main(int argc, char const *argv[])
{
	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	double a4 = 0;
	int a2cont = 0;
	int N;
	scanf("%d", &N);
	int p;
	int flag = -1;
	double a4sum = 0;
	int a4cont = 0;
	for(int i = 0; i < N; i ++)
	{
		scanf("%d", &p);
		switch(p%5)
		{
			case 0:
				if(!(p%2))
					a1 += p;
				break;
			case 1:
				a2cont ++;
				flag *= -1;
				a2 += flag * p;
				break;
			case 2:
				a3 ++;
				break;
			case 3:
				a4sum += p;
				a4cont ++;
				a4 = (double)a4sum/a4cont;
				break;
			case 4:
				if(p > a5)
					a5 = p;
				break;
		}
	}
		if(a1)
			printf("%d ", a1);
		else
			printf("N ");
		if(a2 || ((!a2) && a2cont))		//陷阱,要考虑到a2本身得0的情况.
			printf("%d ", a2);
		else
			printf("N ");
		if(a3)
			printf("%d ", a3);
		else
			printf("N ");
		if(a4)
		{
			printf("%.1f ", a4);
		}
		else
			printf("N ");
		if(a5)
			printf("%d\n", a5);
		else
			printf("N\n");
	return 0;
}