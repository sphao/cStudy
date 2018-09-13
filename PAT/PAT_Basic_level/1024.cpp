/*
* @Author: sphao
* @Date:   2018-09-13 20:54:39
* @Last Modified by:   sphao
* @Last Modified time: 2018-09-13 21:35:19
*/

/*
1024 科学计数法 （20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
 */

#include <cstdio>
#include <cstdlib>

int main(){
    char sciNum[10010];
    scanf("%s", &sciNum);

    int cursor = 0; // 游标
    int e = 0;  // 指数
    char eSign; // 指数符号

    // 定位到E
    while (sciNum[cursor] != 'E') {
        cursor++;
    }

    eSign = sciNum[cursor + 1];
    e = atoi(sciNum+cursor + 2);

    // 如果是负数,先输出负号
    if(sciNum[0] == '-') {
        printf("-");
    }

    // 如果指数负号为负
    if (eSign == '-') {
        printf("0.");
        // 输出e-2个0
        for(int i = 0; i < e - 1; i++){
            printf("0");
        }
        printf("%c", sciNum[1]);
        // 输出小数点之后的数
        for(int i = 3; i < cursor; i++){
            printf("%c", sciNum[i]);
        }
    } else {
        // 如果指数符号为正
        for(int i = 1;i < cursor; i++) {
            // 先跳过小数点
            if(sciNum[i] == '.') {
                continue;
            }
            printf("%c", sciNum[i]);
            // 在e+2的位置输出小数点如果小数点不在最右边
            if(i == e + 2 && cursor - 3 != e) {
                printf(".");
            }
        }

        // 输出多余的0
        for(int i = 0; i < e - (cursor - 3); i++) {
            printf("0");
        }

    }
    return 0;
}
