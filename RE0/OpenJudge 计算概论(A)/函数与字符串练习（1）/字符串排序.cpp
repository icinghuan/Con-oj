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
    char c = getchar();//�����س�
    while (n--)
    {
        getline(cin,s);//��getline���������ո�һ����룬�س���getline��������ı�־
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
