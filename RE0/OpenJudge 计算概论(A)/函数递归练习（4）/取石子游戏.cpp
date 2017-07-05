//http://www.cnblogs.com/huashanqingzhu/p/3450280.html

#include<stdio.h>
int f;
int fun(int a,int b);
int main()
{
    int a,b;
    int t,c;
    scanf("%d%d",&a,&b);
    while(a!=0&&b!=0)
    {
        if(a<b)
        {
            t=a;a=b;b=t;
        }
        f=1;//1表示选手赢，-1表示选手1输。
        f=fun(a,b);
        if(f==1)  printf("win\n");
        else printf("lose\n");
        scanf("%d%d",&a,&b);
    }
    return 0;
}
int fun(int a,int b)
{
    int c;
    if((c=a/b)>1||(a%b==0))
        return f;
    else
    {
        f=-f;
    }    return fun(b,a%b);
}

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

bool isWin(int a,int b)
{
    if (a < b)
        swap(a,b);
    if (a / b >= 2)
        return true;
    else
        if (isWin(a/2,b))
            return false;
        else
            return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    while (n != 0&&m != 0)
    {
        if (isWin(n,m))
            cout<<"win"<<endl;
        else
            cout<<"lose"<<endl;
        cin>>n>>m;
    }
    return 0;
}
*/
