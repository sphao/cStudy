/*
* @Author: sphao
* @Date:   2018-08-25 19:03:46
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-01 19:13:29
*/

#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	if(N<5)
	{
		printf("0\n");
		return 0;
	}
	int a[100000] = {1,2};		//除2外全是奇数
	int t = 2;					//从第三个开始存入数组
	int cont = 2;				//数组内素数个数
	int output = 0;				//计数器

	//找出范围内素数并存入数组
	for(int i = 3; i <= N; i += 2)
	{
		int k = 1;				//1为素数 0为非素数
		for(int j = sqrt(i); j > 1; j--)	//从开方后开始除即可
		{
			if(i%j == 0)
			{
				k = 0;			//能被整除，判非素数
			}
		}
		if(k)
		{
			a[t++] = i;
			cont++;
		}
	}

	//输出素数数组
	// for(int i = 0; i < cont; i++)
	// {
	// 	printf("%d%c",
	// 		a[i], ((cont - i-1)>0) ? ' ':'\0');
	// }

	//判断素数对
	for(int i = 0; i < cont; i++)
	{
		if(a[i+1]-a[i] == 2)
			output++;
	}
	printf("%d\n", output);

	return 0;
}