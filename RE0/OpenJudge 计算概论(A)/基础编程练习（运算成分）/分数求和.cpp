#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int gcd(int m,int n)
{
    return (m==0)?n:gcd(n%m, m);
}
int main()
{
    int n;
    cin>>n;
    int sa = 0,sb = 1;
    while (n--)
    {
        int a,b;
        scanf("%d/%d",&a,&b);//sa/sb + a/b
        sa = sa*b+a*sb;
        sb = sb*b;
    }
    int g = gcd(sa,sb);
    if (sb/g == 1)
        cout<<sa/g<<endl;
    else
        cout<<sa/g<<"/"<<sb/g<<endl;
    return 0;
}
