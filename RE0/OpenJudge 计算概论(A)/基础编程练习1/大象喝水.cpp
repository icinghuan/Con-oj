#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double h,r;
    cin>>h>>r;
    double pi = 3.1415926;
    double v = pi * h * r * r;
    int n = ceil(20000.0/v);//����ȡ��Ϊceil������ȡ��Ϊfloor����������Ϊround
    cout<<n<<endl;
    return 0;
}

