#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<ctime>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int N = 100000 + 5;
int n,a[N],d[N],dd[N];
long long ans;

void qsort(int l,int r)
{
    if (l >= r)
        return;
    int i = l, j = r, x = d[rand()%(j-i+1)+i];
    while(i <= j)
    {
        while (d[i] > x) i++;
        while (d[j] < x) j--;
        if (i<=j)
        {
            swap(d[i],d[j]);
            i++;
            j--;
        }
    }
    qsort(l,i-2);
    qsort(i,r);
}

int main()
{
    //freopen("1002.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        ans = 0;
        scanf("%d",&n);
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);
        }
        FOR(i,1,n-1)
        {
            d[i] = abs(a[i+1]-a[i]);
            dd[i] = d[i];
        }
        qsort(1,n-1);
        if (dd[1] == d[1])
            ans += d[2];
        else
            ans += d[1];
        if (dd[n-1] == d[1])
            ans += d[2];
        else
            ans += d[1];
        int j;
        bool flag;
        FOR(i,2,n-1)
        {
            j = 1;
            flag = false;
            if (dd[i-1] == d[j])
            {
                flag = true;
                j++;
            }
            if (dd[i] == d[j])
                j++;
            if (!flag&&dd[i-1] == d[j])
                    j++;
            if (abs(a[i+1]-a[i-1]) > d[j])
                ans += abs(a[i+1]-a[i-1]);
            else
                ans += d[j];
        }
        cout<<ans<<endl;
    }
    //fclose(stdin);
    return 0;
}
