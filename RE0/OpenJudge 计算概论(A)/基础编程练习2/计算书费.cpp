#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    double b[10] = {28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
    double sum;
    int N;
    cin>>N;
    while (N--)
    {
        sum = 0;
        int k;
        for (int i = 0; i < 10; ++i)
        {
            cin>>k;
            sum += k * b[i];
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}

