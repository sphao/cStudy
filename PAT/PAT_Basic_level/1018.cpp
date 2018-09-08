/*
* @Author: sphao
* @Date:   2018-09-08 20:58:03
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-08 23:13:24
*/

/*
1018 锤子剪刀布（20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
 */

#include <cstdio>

typedef struct jy
{
	char c;
	int win;
	int loss;
	int draw;
	int bwin;
	int jwin;
	int cwin;
	jy()
	{
		c = 0;
		win = 0;
		loss = 0;
		draw = 0;
		bwin = 0;
		jwin = 0;
		cwin = 0;
	}
}JY;

void judge(JY &j, JY &y)
{
	if(j.c == 'B')
	{
		if(y.c == 'J')
		{
			j.loss++;
			y.win++;
			y.jwin++;
		}
		if(y.c == 'B')
		{
			j.draw++;
			y.draw++;
		}
		if(y.c == 'C')
		{
			j.win++;
			y.loss++;
			j.bwin++;
		}
		return;
	}
	if(j.c == 'J')
	{
		if(y.c == 'C')
		{
			j.loss++;
			y.win++;
			y.cwin++;
		}
		if(y.c == 'J')
		{
			j.draw++;
			y.draw++;
		}
		if(y.c == 'B')
		{
			j.win++;
			y.loss++;
			j.jwin++;
		}
		return;
	}
	if(j.c == 'C')
	{
		if(y.c == 'B')
		{
			j.loss++;
			y.win++;
			y.bwin++;
		}
		if(y.c == 'C')
		{
			j.draw++;
			y.draw++;
		}
		if(y.c == 'J')
		{
			j.win++;
			y.loss++;
			j.cwin++;
		}
		return;
	}
}

char max(JY x)
{
	if(x.jwin > x.bwin)
	{
		if(x.jwin > x.cwin)
		{
			return 'J';
		}
		else
		{
			return 'C';
		}
	}
	else if(x.jwin < x.bwin)
	{
		if(x.cwin > x.bwin)
		{
			return 'C';
		}
		else
		{
			return 'B';
		}
	}
	else if(x.jwin == x.bwin)
	{
		if(x.cwin > x.jwin)
			return 'C';
		else
			return 'B';
	}
	else
		return 'B';

}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	getchar();			//读取回车！！！
	JY j , y ;
	for(int i = 0; i < N; i++)
	{
		scanf("%c %c", &j.c, &y.c);
		getchar();			//读取回车！！！
		judge(j, y);
	}
	printf("%d %d %d\n", j.win, j.draw, j.loss);
	printf("%d %d %d\n", y.win, y.draw, y.loss);
	printf("%c %c\n", max(j), max(y));
	return 0;
}