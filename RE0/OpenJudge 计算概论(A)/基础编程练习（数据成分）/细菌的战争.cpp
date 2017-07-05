#include<iostream>

using namespace std;

int main()
{
    int n;
    int a,b;
    int time;
    cin>>n;
    while (n--)
    {
        cin>>a>>b;
        time = 1;
        while (true)
        {
            a -= b;
            if (a <= 0)
            {
                cout<<time<<endl;
                break;
            }
            a *= 2;
            if (a > 1000000)
                a = 1000000;
            b += b/20;
            time++;
        }
    }
    return 0;
}

