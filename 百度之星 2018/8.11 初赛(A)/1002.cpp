#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

using namespace std;

class Deque{
    int val;
    Deque pre;
    Deque next;

    Deque(int val)
    {
        this.val = val;
    }
};

void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int n,q;

Deque head[150005];
Deque tail[150005];

int op,u,v,w,val;

int main()
{
    read(n);
    read(q);
    for(int ii = 0; ii < q; ++ii)
    {
        read(op);
        if (op == 1)
        {
            read(u);
            read(w);
            read(val);
            if (w == 0)
            {
                if (head[u] == NULL)
                {
                    head[u] = new Deque(val);
                    tail[u] = new Deque(val);
                } else {
                    Deque newDeque = new Deque(val);
                    newDeque.next = head[u];
                    head[u].pre = newDeque;
                    head[u] = newDeque;
                }
            }
            if (w == 1)
            {
                if (tail[u] == NULL)
                {
                    head[u] = new Deque(val);
                    tail[u] = new Deque(val);
                } else {
                    Deque newDeque = new Deque(val);
                    newDeque.pre = tail[u];
                    tail[u].next = newDeque;
                    tail[u] = newDeque;
                }
            }
        }
        if (op == 2)
        {
            read(u);
            read(w);
            if (w == 0)
            {
                if (head[u] == NULL)
                {
                    printf("-1\n");
                } else {
                    printf("%d\n",head[u].val);
                    head[u] = head[u].next;
                    if (head[u] == NULL)
                    {
                        tail[u] == NULL;
                    }
                }
            }
            if (w == 1)
            {
                if (tail[u] == NULL)
                {
                    printf("-1\n");
                } else {
                    printf("%d\n",tail[u].val);
                    tail[u] = tail[u].next;
                    if (tail[u] == NULL)
                    {
                        head[u] == NULL;
                    }
                }
            }
        }
        if (op == 3)
        {
            read(u);
            read(v);
            read(w);
            if (w == 0)
            {
                tail[u].next = head[v];
                tail[u] = tail[v];
                head[v] = NULL;
                tail[v] = NULL;
            }
            if (w == 1)
            {
                Deque newDeque = tail[v];
                while (newDeque.pre != NULL)
                {
                    tail[u].next = newDeque;
                    tail[u] = newDeque;
                    newDeque = newDeque.pre;
                }
                tail[u] = head[v];
                head[v] = NULL;
                tail[v] = NULL;
            }
        }
    }
    return 0;
}
