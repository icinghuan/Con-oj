#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    long long ans;
    while (scanf("%d",&n) != EOF)
    {
        if (n%2 == 1)
            ans = ((n+1)/2)*n;
        else
            ans = (n/2)*(n+1);
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
