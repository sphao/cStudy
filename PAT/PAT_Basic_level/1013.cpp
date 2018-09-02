/*
* @Author: sphao
* @Date:   2018-09-02 18:43:49
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-02 21:10:13
*/

/*
1013 数素数（20 分）
令 Pi表示第i个素数。现任给两个正整数M≤N≤104，请输出P​M到P​N的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。

输出格式：
输出从P​M到P​N的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
 */

#include <cstdio>

const int maxLen = 1000004;
bool p[maxLen]={false};
int prime[maxLen],primCount = 0;


void FinePrime(){
	for(int i=2;i<maxLen;i++){
		if(p[i]==false)
		{
			prime[primCount] = i;
			primCount++;
		}
		//删除所有i的倍数
		for(int j = i + i; j < maxLen; j += i)
		{
			p[j] = true;
		}
	}
}


int main(int argc, char const *argv[])
{
	int m, n;
	int t = 0;
	int s = 0;
	scanf("%d%d", &m, &n);
	FinePrime();
	for(int i = m; i <= n; i++)
	{
		printf("%d", prime[i-1]);
		s++;
		if(s%10 == 0)
				printf("\n");
			else if(i < n)
				printf(" ");
	}
	return 0;
}