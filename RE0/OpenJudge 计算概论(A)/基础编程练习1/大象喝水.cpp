#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double h,r;
    cin>>h>>r;
    double pi = 3.1415926;
    double v = pi * h * r * r;
    int n = ceil(20000.0/v);//向上取整为ceil，向下取整为floor，四舍五入为round
    cout<<n<<endl;
    return 0;
}

