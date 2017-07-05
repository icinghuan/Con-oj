#include<iostream>

using namespace std;

int a[105];

int main()
{
    int n;
    cin>>n;
    int sa = 0,sb = 0,sc = 0;
    while (n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sa += a;
        sb += b;
        sc += c;
    }
    cout<<sa<<" "<<sb<<" "<<sc<<" "<<sa+sb+sc<<endl;
    return 0;
}

