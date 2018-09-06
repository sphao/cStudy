/*
* @Author: sphao
* @Date:   2018-09-06 16:54:23
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-06 19:22:11
*/

/*
1017 A除以B（20 分）
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A=B×Q+R成立。

输入格式：
输入在一行中依次给出A和B，中间以1空格分隔。

输出格式：
在一行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
 */

#include <cstdio>
#include <cstring>

//定义大数的结构体
struct bign
{
	int d[1005];
	int len;		//大数长度
	bign()			//构造函数
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

//将字符数组转换为大数
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i ++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

//大数除法
bign divide(bign a, int b, int &r)
{
	bign c;			//商
	c.len = a.len;			//将商的长度与被除数对齐
	for(int i = a.len - 1; i >= 0; i --)		//从高位开始
	{
		r = r * 10 + a.d[i];		//和上一位余数组合
		if(r < b)			//不够除,该位为0
			c.d[i] = 0;
		else			//够除
		{
			c.d[i] = r / b;			//商
			r = r % b;			//新的余数
		}
	}
	//对高位多余的0进行处理
	while(c.len - 1 >= 1 && c.d[c.len -1] == 0)
	{
		c.len --;			//去除高位的0,同时至少保留一位最低位
	}
	return c;
}

int main(int argc, char const *argv[])
{
	char c[1010];			//字符数组
	int b;			//被除数
	int r = 0;			//余数初始为0
	scanf("%s %d", c, &b);
	bign a = change(c);			//转换为大数
	bign q = divide(a, b, r);			//进行除法运算
	for(int i = q.len - 1; i >= 0; i --)		//从高位开始输出大数
	{
		printf("%d", q.d[i]);
	}
	printf(" %d\n", r);			//输出余数
	return 0;
}