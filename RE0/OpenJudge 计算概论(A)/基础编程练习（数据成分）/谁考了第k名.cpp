#include<iostream>
#include<algorithm>

using namespace std;

struct student
{
    int num;
    float grade;
} stu[105];

bool cmp(student a,student b)
{
    if (a.grade > b.grade)
        return true;
    else
        return false;
}

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
        cin>>stu[i].num>>stu[i].grade;
    sort(stu,stu+n,cmp);
    cout<<stu[k-1].num<<" "<<stu[k-1].grade<<endl;//数组从0开始，所以第k名是k-1
    return 0;
}

