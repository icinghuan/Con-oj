/*
 * binaries.cpp
 *
 *  Created on: 2014-5-22
 *      Author:
 *      2:输出二进制补码
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入若干int型整数，输出每个整数的二进制补码。

输入
输入有若干行，除最后一行外，每行包含一个int型整数。最后一行仅包含一个不定的字母，标志着输入结束。我们保证输入的整数不超出int型变量的表示范围
输出
个输入的整数，输出一行，即该整数的补码表示。
样例输入
1
7
200
-45
h
样例输出
00000000000000000000000000000001
00000000000000000000000000000111
00000000000000000000000011001000
11111111111111111111111111010011
 */
#include<stdio.h>
#include<stdlib.h>
void out(int n,int l){
    for (int i=31;i>=0;i--)
        printf("%d",(n&(1<<i))!=0);
}
int main(){
    char s[16];
    for (;scanf("%s",s)&&((s[0]>='0'&&s[0]<='9')||s[0]=='-');out(atoi(s),31),printf("\n"));
    return 0;
}

/*
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<bitset>

const int maxn = 1000 + 5;
using namespace std;

int n, m, T, Ar, Sa;

int main()
{
while(cin>>n)
cout<<bitset<sizeof(int)*8>(n)<<endl;
return 0;
}
*/
