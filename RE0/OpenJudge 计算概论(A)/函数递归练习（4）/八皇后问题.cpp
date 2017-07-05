# include<iostream>
using namespace std;

int colFirst[9];//colFirst[j]=i，记录第j列上的queen在第i行
int count=0;

void PrintResult()
{
    int rowFirst[9];
    for(int col=1;col<=8;col++)
    {
        int row=colFirst[col];
        rowFirst[row]=col;
    }
    cout<<"No. "<<count<<endl;
    for(int row=1;row<=8;row++)
    {
        for(int colBefore=1;colBefore<rowFirst[row];colBefore++)
        {
            cout<<"0 ";
        }
        cout<<"1 ";
        for(int colAfter=rowFirst[row]+1;colAfter<=8;colAfter++)
        {
            cout<<"0 ";
        }
        cout<<endl;
    }
}

bool OK(int curCol, int curRow)
{
    for(int j=1;j<curCol;j++)
    {
        if(colFirst[j]==curRow || colFirst[j]+(curCol-j)==curRow || colFirst[j]-(curCol-j)==curRow)
        {
            return false;
        }
    }
    return true;
}

void Queue(int curCol)
{
    for(int curRow=1;curRow<=8;curRow++)
    {
        if(OK(curCol,curRow))
        {
            colFirst[curCol]=curRow;
            if(curCol==8)
            {
                count++;
                PrintResult();
            }
            Queue(curCol+1);
        }
    }
}

int main()
{
    Queue(1);
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
//我也不太清楚顺序应该是啥
using namespace std;

const int N = 8;
int n;
bool fl[20];
int ans[20];
int k = 0;
bool flag;

void dfs()
{
    if (n == N)
    {
        k++;
        cout<<"No. "<<k<<endl;
        FOR(i,1,N)
        {
            FOR(j,1,N)
            {
                if (j == ans[i])
                    cout<<"1 ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
        return;
    }
    FOR(i,1,N)
    {
        if (!fl[i])
        {
            flag = false;
            FOR(j,1,n)
                if (i-ans[j] == n-j+1||ans[j]-i == n-j+1)
                    flag = true;
            if (flag)
                continue;
            n++;
            fl[i] = true;
            ans[n] = i;
            dfs();
            ans[n] = 0;
            fl[i] = false;
            n--;
        }
    }
}

int main()
{
    freopen("1.txt","w",stdout);
    n = 0;
    FOR(i,1,N)
    {
        fl[i] = false;
        ans[i] = 0;
    }
    dfs();
    fclose(stdout);
    return 0;
}
*/
