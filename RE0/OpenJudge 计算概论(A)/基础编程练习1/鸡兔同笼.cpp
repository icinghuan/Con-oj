#include<iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    if (a % 2 != 0)
        cout<<"0 0"<<endl;
    else
    {
        int Min = a / 4 + a % 4 / 2;
        int Max = a / 2;
        cout<<Min<<" "<<Max<<endl;
    }
    return 0;
}
