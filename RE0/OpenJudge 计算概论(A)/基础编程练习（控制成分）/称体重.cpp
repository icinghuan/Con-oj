#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

struct weight
{
    char name;
    int weig;
} w[4];

bool cmp(weight a,weight b)
{
    if (a.weig < b.weig)
        return true;
    else
        return false;
}

int main()
{
    int z,q,s,l;
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
            for (int k = 1; k <= 5; ++k)
                for (int n = 1; n <= 5; ++n)
                    if (i+j == k+n&&i+n > j+k&&i+k < j)
                    {
                        z = 10*i;
                        q = 10*j;
                        s = 10*k;
                        l = 10*n;
                    }
    w[0].name = 'z';w[0].weig = z;
    w[1].name = 'q';w[1].weig = q;
    w[2].name = 's';w[2].weig = s;
    w[3].name = 'l';w[3].weig = l;
    sort(w,w+4,cmp);
    for (int i = 0; i < 4; ++i)
        cout<<w[i].name<<" "<<w[i].weig<<endl;
    return 0;
}
