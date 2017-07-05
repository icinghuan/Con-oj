#include<iostream>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int sum = 0;
    for (int i = m; i <= n; ++i)
        if (i % 2 != 0)
            sum += i;
    cout<<sum<<endl;
    return 0;
}
//因为这题只到300所以直接循环就行，如果很大就可以换成公式来求
