/*
* @Author: sphao
* @Date:   2018-09-05 09:30:07
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-05 11:04:14
*/

/*
1016 部分A+B（15 分）
正整数A的“D​A（为1位整数）部分”定义为由A中所有D​A组成的新整数P​A。例如：给定A=3862767，D​A=6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA+PB。

输入格式：
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中 0<A,B<10^10。

输出格式：
在一行中输出PA+PB的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
 */

#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
	char a[11] = {0};
	char b[11] = {0};
	int da, db;
	int pa = 0, pb = 0;
	double p = 10;
	scanf("%s", a);
	scanf("%d", &da);
	scanf("%s", b);
	scanf("%d", &db);
	int conta = 0, contb = 0;
	for(int i = 0; a[i] != '\0'; i++)
	{
		if((a[i] - '0') == da)
		{
			conta ++;
		}
	}
	for(int i = 0; b[i] != '\0'; i++)
	{
		if((b[i] - '0') == db)
		{
			contb ++;
		}
	}
	for(int i = 0; i < conta; i ++)
	{
		if(conta == 0)
		{
			pa = 0;
			break;
		}
		pa += da * (int)pow(p, i);
	}
	for(int i = 0; i < contb; i ++)
	{
		if(contb == 0)
		{
			pb = 0;
			break;
		}
		pb += db * (int)pow(p, i);
	}
	printf("%d\n", pa + pb);
	return 0;
}
