#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

int year,month,day;
int T;

int getWeekdayByYearday(int iY, int iM, int iD)
{
    int iWeekDay = -1;
    if (1 == iM || 2 == iM)
    {
        iM += 12;
        iY--;
    }
    iWeekDay = (iD + 1 + 2 * iM + 3 * (iM + 1) / 5 + iY + iY / 4 - iY / 100 + iY / 400) % 7;
    return iWeekDay;
}

int findyear()
{
    int k;
    if (month == 2&&day == 29)
    {
        k = year+4;
        if (k%100 == 0&&k%400 != 0)
            k = k+4;
    }
    else
        k = year+1;
    int weekday = getWeekdayByYearday(year,month,day);
    //cout<<year<<month<<day<<endl;
    //cout<<weekday<<endl;
    while (true)
    {
        if (getWeekdayByYearday(k,month,day) == weekday)
            return k;
        if (month == 2&&day == 29)
        {
            k = k+4;
            if (k%100 == 0&&k%400 != 0)
                k = k+4;
        }
        else
            k++;
    }
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d-%d-%d",&year,&month,&day);
        printf("%d\n",findyear());
    }
    return 0;
}
