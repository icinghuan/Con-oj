#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    int a = 0,b = 0,c = 0,d = 0;
    cin>>n;
    int N = n;
    while (n--)
    {
        int k;
        cin>>k;
        if (k <=18) a++;
        if (k >= 19&&k <= 35) b++;
        if (k >= 36&&k <= 60) c++;
        if (k > 60) d++;
    }
    printf("1-18: %.2lf%%\n",double(a)/double(N)*100.0);
    printf("19-35: %.2lf%%\n",double(b)/double(N)*100.0);
    printf("36-60: %.2lf%%\n",double(c)/double(N)*100.0);
    printf("60-: %.2lf%%\n",double(d)/double(N)*100.0);
    return 0;
}
