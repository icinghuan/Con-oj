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
    cin>>n;
    while (n != 0)
    {
        int ma = 1;
        int now = 1;
        int k = 0;
        cin>>k;
        n--;
        int before = k;
        while (n--)
        {
            cin>>k;//从第2个开始
            if (before == k)
            {
                now++;
            }
            else
            {
                before = k;
                if (now > ma)
                    ma = now;
                now = 1;
            }
        }
        cout<<ma<<endl;
        cin>>n;
    }
    return 0;
}
