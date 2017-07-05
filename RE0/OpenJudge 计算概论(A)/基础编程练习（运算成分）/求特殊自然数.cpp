#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

//编译器不认itoa函数，所以改成手动实现
char *itoa_my(int value,char *string,int radix)
{
    char zm[37]="0123456789abcdefghijklmnopqrstuvwxyz";
    char aa[100]={0};

    int sum=value;
    char *cp=string;
    int i=0;

    if(radix<2||radix>36)//增加了对错误的检测
    {
        cout<<"error data!"<<endl;
        return string;
    }

    if(value<0)
    {
        cout<<"error data!"<<endl;
        return string;
    }


    while(sum>0)
    {
        aa[i++]=zm[sum%radix];
        sum/=radix;
    }

    for(int j=i-1;j>=0;j--)
    {
        *cp++=aa[j];
    }
    *cp='\0';
    return string;
}
/*
这道题其实不需要通用的转换进制函数
都是三位的
int seven(int n)
{return (n%7+10*(n%49-n%7)/7+100*(n%343-n%49)/49+1000*(n%(343*7)-n%343)/343);}
int nine(int n)
{return (n%9+10*(n%81-n%9)/9+100*(n%729-n%81)/81+1000*(n%(729*9)-n%729)/729);}
用上面的更简洁，但只能用于特定情况
*/

int main()
{
    //(100)7 = 7*7 = 49
    //(111)7 = 7*7*7-1 = 342
    //(100)9 = 9*9 = 81
    //(111)9 = 9*9*9-1 = 728
    // 729-2400
    int ans = 0;
    char a[10];
    char b[10];
    for (int i = 49; i <= 728; ++i)
    {
        //cout<<i<<endl;
        itoa_my(i,a,7);//将一整型数值转换为任意2~36进制的字符串保存
        itoa_my(i,b,9);
       // printf("%s %s\n",a,b);
        bool is = true;
        if (a[0] != b[2])
            is = false;
        if (a[1] != b[1])
            is = false;
        if (a[2] != b[0])
            is = false;
        if (is)
            ans = i;
    }
    int k;
    cin>>k;
    itoa_my(ans,a,7);
    itoa_my(ans,b,9);
    if (k == 1)
        cout<<ans<<endl;
    if (k == 2)
        printf("%s\n",a);
    if (k == 3)
        printf("%s\n",b);
}
