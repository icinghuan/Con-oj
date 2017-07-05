#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    double n;
    while (N--)
    {
        cin>>n;
        double time1,time2;
        time1 = 27+23+n/3;
        time2 = n/1.2;
        if (time1 < time2)
            cout<<"Bike"<<endl;
        if (time1 > time2)
            cout<<"Walk"<<endl;
        if (time1 == time2)
            cout<<"All"<<endl;
    }
    return 0;
}

