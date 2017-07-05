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
    double a,b;
    cin>>n;
    cin>>a>>b;
    double x = b/a;
    n--;
    while (n--)
    {
        cin>>a>>b;
        double y = b/a;
        if (y-x > 0.05)
            cout<<"better"<<endl;
        else
            if (x-y > 0.05)
                cout<<"worse"<<endl;
            else
                cout<<"same"<<endl;
    }
    return 0;
}
