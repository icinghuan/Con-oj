#include<iostream>

using namespace std;

template<typename T>
void Swap(T &a,T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    double a,b;
    cin>>a>>b;
    Swap(a,b);
    cout<<a<<' '<<b<<endl;
    return 0;
}
