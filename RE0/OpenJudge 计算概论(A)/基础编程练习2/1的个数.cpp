#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int n;
    while (N--)
    {
        cin>>n;
        int sum = 0;
        while (n != 0)
        {
            if (n % 2 != 0)
                sum++;
            n = n >> 1;//位运算，右移一位
        }
        cout<<sum<<endl;
    }
    return 0;
}

