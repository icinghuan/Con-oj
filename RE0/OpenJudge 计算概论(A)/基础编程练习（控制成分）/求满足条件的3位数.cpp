#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[15];
    int k = 1;
    for (int i = 100; i <= 999; ++i)
    {
        if (int(sqrt(i))*int(sqrt(i)) == i)
            if (i%10 == i/100||i%10 == i%100/10||i/100 == i%100/10)
            {
                a[k++] = i;
            }
    }
    cout<<a[n]<<endl;
    return 0;
}

//问题出在sqrt(i),我本来以为自动转换类型没有问题
//还得加个int强制转换一下

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[10]={0,100,121,144,225,400,441,484,676,900};
//这题有毒了吧，打表和求值明明一样的，只有打表才能AC。。。
int main()
{
    int N;
    cin>>N;
    int k = 0;
    int n = 0;
    for (int i = 100; i < 1000; ++i)
    {
        if (sqrt(i)*sqrt(i) == i&&(i%10 == i/100||i%10 == i%100/10||i/100 == i%100/10))
        {
            n++;
            //if (n == N)
            {
                //cout<<i<<endl;
                //a[++k] = i;
               // break;
            }
        }
    }
    //for(int i = 0;i<10;++i)
        //cout<<a[i]<<endl;
    cout<<a[N]<<endl;
    return 0;
}*/
/*
0
100
121
144
225
400
441
484
676
900

0
100
121
144
225
400
441
484
676
900
*/
