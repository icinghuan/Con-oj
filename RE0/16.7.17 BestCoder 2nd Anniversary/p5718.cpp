#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

char c[10000005];
int l,k,m;

int main()
{
    int T;
    scanf("%d",&T);
    c[0] = getchar();
    while (T--)
    {
        l = 0;
        scanf("%c",&c[l++]);
        while (c[l-1] != '\n')
            scanf("%c",&c[l++]);
        l--;
        sort(c,c+l);
        k = -1;
        for (int i = 0; i < l-1; ++i)
            if (c[i] != '0')
            {
                k = i;
                break;
            }
        if (k == -1)
            printf("Uncertain\n");
        else
        {
            if (k == 0)
            {
                m = 1;
                c[m] = c[m]+c[k]-'0';
                while (c[m] > '9'&&m < l)
                {
                    c[m] = c[m]-10;
                    c[m+1] += 1;
                    m++;
                }
                if (m == l)
                {
                    l++;
                    c[m] = '1';
                }
            }
            else
            {
                swap(c[1],c[k]);
            }
            for (int i = l-1; i > 0; --i)
                printf("%c",c[i]);
            printf("\n");
        }
    }
    return 0;
}
