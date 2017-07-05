#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string str[205];

int main()
{
    int N;
    cin>>N;
    while (N--)
    {


    string s;
    int k = 0;
    int n;
    cin>>n;
    char c = getchar();//读掉回车
    while (n--)
    {
        getline(cin,s);//用getline读可以连空格一起读入，回车是getline读入结束的标志
        str[k] = s;
        k++;
    }
    sort(str,str+k);
    for (int i = 0; i < k; ++i)
        cout<<str[i]<<endl;
    cout<<endl;



    }
    return 0;
}
