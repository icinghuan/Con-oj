#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>b;--i)

using namespace std;

const int MAX = 10000000;
//int a[10] = {2,3,1,5,7,9,8,6,0,4};
int a[MAX+5];

void qsort(int l,int r)
{
    if (l >= r)
        return;
    int i = l, j = r, x = a[rand()%(j-i+1)+i];
    while(i <= j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    qsort(l,i-2);
    qsort(i,r);
}

int main()
{
    srand((unsigned)time(NULL));
    FOR(i,0,MAX)
        a[i] = rand();
    qsort(0,MAX-1);
    //sort(a,a+MAX);
    //FOR(i,0,MAX)
        //cout<<a[i]<<' ';
    //cout<<RAND_MAX<<endl;
    //FOR(i,0,10)
        //cout<<rand()<<" "<<endl;
    return 0;
}
