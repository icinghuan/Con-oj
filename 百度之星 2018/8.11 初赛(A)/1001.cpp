#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

using namespace std;

const int MAXN = 1000 + 5;
int a[MAXN];
int n;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        bool flag=false;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=n-1;i>1;i--)
        {
            if(a[i]<a[i-1]+a[i-2])
            {
                flag=true;
                printf("%d\n",a[i]+a[i-1]+a[i-2]);
                break;
            }
        }
        if(!flag)
        printf("-1\n");
    }
    return 0;
}
