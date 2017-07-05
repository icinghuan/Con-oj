#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    double sum = 0;
    cin>>n;
    while (n--)
    {
        int k;
        cin>>k;
        if (k % 70 == 0)
            sum += k / 70;
        else
            sum += k / 70 + 1;
    }
    printf("%.1lf\n",sum*0.1);
    return 0;
}
