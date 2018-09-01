/*
* @Author: sphao
* @Date:   2018-08-31 18:24:01
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-01 19:14:34
*/

/*
1010 一元多项式求导（25 分）
设计函数求一元多项式的导数。

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0
 */

#include <cstdio>

int main(int argc, char const *argv[])
{
	int a, n;
	int f = 0;
	do{
		scanf("%d%d", &a, &n);
		if(a ==0)
			continue;
		if(n != 0)
		{
			a = a*n;
			n = n-1;
			if(!(a == 0 && n == 0))
			{
				if(f == 0)
				{
					printf("%d %d", a, n);
					f = 1;
				}
				else
				{
					printf(" %d %d", a, n);
				}
			}
		}
	}while(getchar() != '\n');
	if(f == 0)
		printf("0 0\n");
	return 0;
}