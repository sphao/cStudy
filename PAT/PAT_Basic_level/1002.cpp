/*
* @Author: sphao
* @Date:   2018-08-03 23:04:20
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-14 22:48:35
*/

/*
1002 写出这个数 (20)（20 分）
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100^。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：

1234567890987654321123456789
输出样例：

yi san wu
 */

#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
	char c[101];
	char pinyin[][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int s[10];
	scanf("%s", c);			//PAT中无法使用gets！
	int i, sum = 0, t =0;
	for(i = 0; i < strlen(c); i ++)
	{
		sum = sum + c[i] - '0';
	}
	while(sum != 0)
	{
		s[t] = sum % 10;
		sum = sum / 10;
		t++;
	}
	for (i = t-1; i >=0; i--)
	{
		printf("%s", pinyin[s[i]]);
		if((i - 1) >= 0)
			putchar(' ');
	}
	putchar(10);
	return 0;
}