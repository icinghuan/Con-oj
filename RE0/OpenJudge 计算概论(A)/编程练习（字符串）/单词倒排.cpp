#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string str[100];

int main()
{
    string s;
    int k = 0;
    while (cin>>s)//cin�����ַ������ӿո�ͻس����ո�ͻس���Ϊ�ָ�����
        //����cin����������������
    {
        str[k] = s;
        k++;
    }
    for (int i = k-1; i >= 0; --i)
        cout<<str[i]<<" ";
    return 0;
}
