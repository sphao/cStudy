/*
* @Author: sphao
* @Date:   2018-05-04 22:16:11
* @Last Modified by:   sphao
* @Last Modified time: 2018-05-04 23:31:03
*/
#include <cstdio>
#include <cctype>
#include <cstdbool>
#define STOP '|'

int main(void)
{
	char c;					//读入字符
	char prev;				//读入前一个字符
	long n_chars = 0L;		//字符数
	int n_lines = 0;		//行数
	int n_words = 0;		//单词数
	int p_lines = 0;		//不完整的行数
	bool inword = false;
	
	prev = '\n';
	while((c = getchar()) != STOP)
	{
		n_chars++;
		if(c == '\n')
			n_lines++;
		if(!isspace(c) && !inword)
		{
			inword = true;	//开始一个新的单词
			n_words++;		//统计单词
		}
		if (isspace(c) && inword)
		{
			inword = false;
		};
		prev = c;
	}
	if (prev != '\n')
	{
		p_lines = 1;
	}
	printf("characters = %ld, words = %d, lines = %d, ",
		n_chars, n_words, n_lines);
	printf("partial lines =  %d\n", p_lines);
}