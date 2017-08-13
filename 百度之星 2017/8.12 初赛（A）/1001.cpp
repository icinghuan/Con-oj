#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

int P,T;

int factors(int N)
{
    if (N == 1)
        return 1;
    int count = 2;// 1 与 N
    int r;
    for(int i = 2; i <= sqrt(N); i++)
    {
        if(N % i == 0)
        {
            if(i == sqrt(N))
            {
                r = N / i;
                if(r == i){//比如 4 = 2 * 2；那么2 只能算一个
                    count++;
                }else{
                    count += 2;
                }
            }else{
                count += 2;
            }
        }
    }
    return count;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&P);
        printf("%d\n",factors(P-1));
    }
    return 0;
}
