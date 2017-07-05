#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum = 0;
    int N = n;
    while (n--)
    {
        int age;
        cin>>age;
        sum += age;
    }
    printf("%.2lf",double(sum)/double(N));
    return 0;
}

