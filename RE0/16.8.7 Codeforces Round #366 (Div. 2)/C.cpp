#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<ctime>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define mp(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

using namespace std;

typedef long long LL;

const int N = 300000 + 5;
struct Node{
    int k = 0;
    Node* next;
};
Node* head[N],tail[N];

int main()
{
    FOR(i,1,N)
        head[i] = tail[i] = NULL;
    int n, q, t, x, num = 0;
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d%d",&t,&x);
        if (t == 1)
        {
            num++;
            Node* ne = new Node;
            if (head[x] == NULL)
                head[x].next = ne;
            else
                tail[x].next = ne;
            tail[x] = ne;
            ne.k = num;
            head[x].k++;
        }
        if (t == 2)
        {


        }
        if (t == 3)
        {

        }
        printf("%d\n",);
    }
    return 0;
}
