/*
* @Author: sphao
* @Date:   2018-08-24 08:11:19
* @Last Modified by:   sphao
* @Last Modified time: 2018-08-24 09:11:19
*/
 /*
 1004 成绩排名 (20)（20 分）
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为\

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：

Mike CS991301
Joe Math990112
  */

#include <cstdio>

struct Student{
	char name[15];
	char id[15];
	int score;
}max,min,temp;

int main(){
	int n;
	scanf("%d",&n);

	min.score = 101;
	max.score = -1;
	while(n--){
		scanf("%s%s%d",temp.name,temp.id,&temp.score);
		if(temp.score < min.score)	min = temp;
		if(temp.score > max.score)  max = temp;
	}

	printf("%s %s\n",max.name,max.id);
	printf("%s %s\n",min.name,min.id);

	return 0;
}