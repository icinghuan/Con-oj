#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    double n;
    cin>>n;
    double sum = n;
    for (int i = 1; i <= 9; ++i)
    {
        sum += n;
        n = n*0.5;
    }
    cout<<sum<<endl;
    cout<<n*0.5<<endl;
    return 0;
}
