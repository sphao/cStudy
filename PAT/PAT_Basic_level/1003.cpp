/*
* @Author: sphao
* @Date:   2018-08-04 17:41:51
* @Last Modified by:   sphao
* @Last Modified time: 2018-08-23 22:29:21
*/
/*
1003 我要通过！(20)（20 分）
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；\

任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；\
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (&lt10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：

YES
YES
YES
YES
NO
NO
NO
NO
 */

#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i< t; i++)
	{
		char arr[101];
		scanf("%s", arr);
		int a = 0, b = 0, c = 0;
		int k = 1;
		int A = 0, B = 0, C = 0;
		for(int j = 0; j < strlen(arr); j++)
		{
			if(arr[j] != 'P' && arr[j] != 'A' && arr[j] != 'T')
			{
				k = 0;
			}
		}
		if(!k)
			{
				k =0;
			}
		// if(arr[0] != 'A' && arr[0] != 'P')
		// 	{
		// 		printf("NO\n");
		// 		return -1;
		// 	}
		while(arr[A] == 'A')
		{
			a++;
			A++;
		}
		if(arr[A] != 'P')
		{
			k = 0;
		}
		B = A+1;
		// if(arr[B] != 'A' && arr[0] != 'T')
		// 	{
		// 		printf("NO\n");
		// 		return -1;
		// 	}
		while(arr[B] == 'A')
		{
			b++;
			B++;
		}
		if(arr[B] != 'T')
		{
			k = 0;
		}
		C = B+1;
		while(arr[C] == 'A')
		{
			c++;
			C++;
		}
		if(C != strlen(arr))
		{
			k = 0;
		}
		if(c != a * b)
			k = 0;
		if(b == 0)
			k = 0;
		if(k == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}