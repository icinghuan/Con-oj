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
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            cout<<n<<"/2=";
            n = n/2;
            cout<<n<<endl;
        }
        else
        {
            cout<<n<<"*3+1=";
            n = n * 3 + 1;
            cout<<n<<endl;
        }
    }
    cout<<"End"<<endl;
    return 0;
}
