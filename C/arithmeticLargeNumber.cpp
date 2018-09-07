/*
* @Author: sphao
* @Date:   2018-09-06 16:54:23
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-07 17:55:11
*/

/*
大数的四则运算，没有考虑负数，若涉及到负数，自行添加条件判断，在change中将其统一进行了取绝对值，可添加条件进行符号处理，将其转换为正整数的四则运算。
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
	if(a.d[a.len - 1] == '-' - '0')
		a.len --;
	return a;
}

//大数加法
bign add(bign a, bign b)
{
	bign c;			//和
	int carry = 0;			//进位
	for(int i = 0; i < a.len || i < b.len; i ++)		//以较长的为界限
	{
		int temp = a.d[i] + b.d[i] + carry;			//两个对应位与进位相加
		c.d[c.len++] = temp % 10;			//个位数为该位结果
		carry = temp / 10;			//十位数为新的进位
	}
	if(carry != 0)			//最后进位不为0，则直接赋值给结果的最高位
	{
		c.d[c.len++] = carry;
	}
	return c;
}

//大数减法
bign sub(bign a, bign b)
{
	bign c;
	for(int i = 0; i < a.len || i < b.len; i ++)			//从低位开始减，以较长的为界限
	{
		if(a.d[i] < b.d[i])			//不够减
		{
			a.d[i + 1]--;			//借位
			a.d[i] += 10;			//当前位加10
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)			//去除高位0，同时保留至少一位
	{
		c.len--;
	}
	return c;
}

//大数乘法
bign multi(bign a, int b)
{
	bign c;
	int carry = 0;			//进位
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;			//个位作为结果
		carry = temp / 10;			//高位作为新的进位
	}
	while(carry != 0)			//与加法不同，乘法进位可能不止一位，所以用while
	{
		c.d[i++] = carry % 10;
		carry /= 10;
	}
	return c;
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
	char a[1010];
	char b[1010];			//字符数组
	scanf("%s %s", a, b);
	bign A = change(a);			//转换为大数
	bign B = change(b);
	bign C;
	C = add(A, B);
 	for(int i = C.len - 1; i >= 0; i --)		//从高位开始输出大数
	{
		printf("%d", C.d[i]);
	}
	return 0;
}