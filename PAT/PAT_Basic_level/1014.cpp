/*
* @Author: sphao
* @Date:   2018-09-03 18:06:03
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-03 19:35:30
*/

/*
1014 福尔摩斯的约会（20 分）
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
THU 14:04
 */

#include <cstdio>

int main(int argc, char const *argv[])
{
	int k = 0;
	char a1[61] = {0};
	char a2[61] = {0};
	char a3[61] = {0};
	char a4[61] = {0};
	scanf("%s", a1);
	scanf("%s", a2);
	scanf("%s", a3);
	scanf("%s", a4);
	for(int i = 0; i < 60; i ++)
	{
		if((a1[i] == a2[i]) && a1[i] >= 'A' && a1[i] <= 'G' && k == 0)		//第一对相同的大写字母只从'A'到'G',莫要将范围扩大.
		{
			k = 1;
			if(a1[i] == 'A')
				printf("MON ");
			if(a1[i] == 'B')
				printf("TUE ");
			if(a1[i] == 'C')
				printf("WED ");
			if(a1[i] == 'D')
				printf("THU ");
			if(a1[i] == 'E')
				printf("FRI ");
			if(a1[i] == 'F')
				printf("SAT ");
			if(a1[i] == 'G')
				printf("SUN ");
			continue;
		}
		if(k == 1 && a1[i] == a2[i] && ((a1[i] >= 'A' && a1[i] <= 'N' ) || (a1[i] >= '0' && a1[i] <= '9')))			//勤加括号,防止优先级问题,范围同样莫要给多.
		{
			if(a1[i] >= '0' && a1[i] <= '9')
				printf("%02d:", a1[i] - '0');
			if(a1[i] >= 'A' && a1[i] <= 'N')
			{
				int h = 10 + a1[i] - 'A';
				printf("%d:", h);
			}
			break;
		}
	}
	for(int i = 0; i < 61; i ++)
	{
		if(k == 1 && (a3[i] == a4[i]) && ((a3[i] >= 'A' && a3[i] <= 'Z') || (a3[i] >= 'a' && a3[i] <= 'z')))
		{
			k = 2;
			printf("%02d", i);
		}
	}
	return 0;
}