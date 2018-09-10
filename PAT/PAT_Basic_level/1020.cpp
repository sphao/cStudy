/*
* @Author: sphao
* @Date:   2018-09-10 21:33:42
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-10 22:10:36
*/

/*
1020 月饼（25 分）
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：
每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
 */

#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct moonCake
{
	double kc;
	double zj;
	double price;
}MK;

bool cmp(MK a, MK b)
{
	return a.price > b.price;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	MK mk[N];
	for(int i = 0; i < N; i++)
	{
		scanf("%lf", &mk[i].kc);
	}
	for(int i = 0; i < N; i++)
	{
		scanf("%lf", &mk[i].zj);
		mk[i].price = mk[i].zj / mk[i].kc;
	}
	sort(mk, mk + N , cmp);
	double ans = 0;
	for(int i = 0; i < N; i++)
	{
		if(mk[i].kc < M)
		{
			ans += mk[i].price * mk[i].kc;
			M -= mk[i].kc;
		}
		else
		{
			ans += mk[i].price * M;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}