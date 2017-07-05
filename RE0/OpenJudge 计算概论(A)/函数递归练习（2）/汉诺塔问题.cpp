#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
char a,b,c;

void hanoi(int n,char a,char b,char c)
{
    if(n==1)
        cout<<a<<"->"<<n<<"->"<<c<<endl;
    else
    {
        hanoi(n-1,a,c,b);
        cout<<a<<"->"<<n<<"->"<<c<<endl;
        hanoi(n-1,b,a,c);
    }
}

int main()
{
    scanf("%d %c %c %c",&n,&a,&b,&c);
    hanoi(n,a,c,b);
    return 0;
}
