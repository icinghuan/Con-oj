/*
 * binaries.cpp
 *
 *  Created on: 2014-5-22
 *      Author:
 *      2:��������Ʋ���
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
��������int�����������ÿ�������Ķ����Ʋ��롣

����
�����������У������һ���⣬ÿ�а���һ��int�����������һ�н�����һ����������ĸ����־��������������Ǳ�֤���������������int�ͱ����ı�ʾ��Χ
���
����������������һ�У����������Ĳ����ʾ��
��������
1
7
200
-45
h
�������
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
