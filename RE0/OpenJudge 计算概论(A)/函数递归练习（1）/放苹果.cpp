#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

//http://blog.csdn.net/asxutao/article/details/50463070

int coun(int m, int n){
    if (m == 0 || n == 1)
        return 1;
    if (n > m)
        return coun(m, m);
    else
        return coun(m, n - 1) + coun(m - n, n);
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int m,n;
        cin>>m>>n;
        cout<<coun(m,n)<<endl;
    }
    return 0;
}
