#include<iostream>

using namespace std;

int main()
{
    int k;
    int a = 0,b = 0,c = 0;
    int n;
    cin>>k;
    while (k--)
    {
        cin>>n;
        if (n == 1)
            a++;
        if (n == 5)
            b++;
        if (n == 10)
            c++;
    }
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    return 0;
}

