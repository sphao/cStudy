/*
* @Author: sphao
* @Date:   2018-08-03 23:00:14
* @Last Modified by:   sphao
* @Last Modified time: 2018-08-03 23:01:54
*/
#include "cstdio"
int main(void)
{
	int a = 4;
	printf("%d\n", sizeof a+3);
	return 0;
}

//sizeof的优先级比括号及自增自减低，比算数运算符高	。