#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

struct distance
{
    int x1,y1,z1;
    int x2,y2,z2;
    double dist;
}dis[105],tmp;

int a[15][3];

double di(double x1,double y1,double z1,double x2,double y2,double z2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = z;
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
        {
            dis[k].x1 = a[i][0];
            dis[k].y1 = a[i][1];
            dis[k].z1 = a[i][2];
            dis[k].x2 = a[j][0];
            dis[k].y2 = a[j][1];
            dis[k].z2 = a[j][2];
            dis[k].dist = di(a[i][0],a[i][1],a[i][2],a[j][0],a[j][1],a[j][2]);
            k++;
        }
    for (int i = 0; i < k; ++i)
        for (int j = k-1; j > i; --j)
            if (dis[j-1].dist < dis[j].dist)
            {
                tmp = dis[j-1];
                dis[j-1] = dis[j];
                dis[j] = tmp;
            }
    for (int i = 0; i < k; ++i)
    {
        printf("(%d,%d,%d)-(%d,%d,%d)=%.2lf\n",dis[i].x1,dis[i].y1,dis[i].z1,dis[i].x2,dis[i].y2,dis[i].z2,dis[i].dist);
    }
    return 0;
}
