#include<bits/stdc++.h>

using namespace std;

map<string,int>q;
map<string,int>::iterator p;
string f="no";

void add(string s)
{
    p=q.find(s);
    if(p==q.end())q[s]=1;
    else q[s]++;
    f=q[s]>q[f]?s:f;
    return;
}

int main()
{
    int n,i,j,h,m;
    q["no"]=1;
    string s,a;
    cin>>n;
    getline(cin,a);
    for(i=0;i<n;i++)
    {
        cin>>s;
        h=0;
        if(s[0]=='+'||s[0]=='-')
        {
            h=1;
            a=s[0]=='+'?"":"-";
        }
        else
            a="";
        m=s.find_first_not_of('0',h);
        /*1.�������ַ������״γ��ֵĲ�ƥ��str�е��κ�һ���ַ������ַ�����, ��index��ʼ����, ���ȫ��ƥ���򷵻�string::npos��
2.��index��ʼ��������ǰ�ַ���, ����������strǰnum���ַ��е�����һ������ƥ�������, �������������ĵ�һ���ַ�����, ���򷵻�string::npos��
3.�����ڵ�ǰ�ַ����е�һ����ƥ��ch�ַ�������, ��index��ʼ����, û���ջ��򷵻�string::npos��*/
        if(m==string::npos)
        /*npos ��һ��������������ʾ�����ڵ�λ�ã�����һ����std::container_type::size_type ����������ṩ���������ȡֵ��ʵ�־�����һ����-1�����������Ͳ��������ֲ�������ˡ�*/
        {
            add("0");
            continue;
        }
        a+=s.substr(m);
        add(a);
    }
    if(q.size()>2)cout<<f<<endl;
    else cout<<"no"<<endl;
    return 0;
}

//һֱWA�����������ϵı�̣��õ���map��һ�Ѻ���

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

map<string,int>q;
map<string,int>::iterator p;
string f="no";

void add(string s)
{
    p=q.find(s);
    if(p==q.end())q[s]=1;
    else q[s]++;
    f=q[s]>q[f]?s:f;
    return;
}

int main()
{
    int n;
    cin>>n;
    char c;
    c = getchar();
    for (int i = 0; i < n; ++i)
    {
        c = getchar();
        bool f = false;
        string s = "";
        while (c != '\n'&&c != EOF)
        {
            if (c == '+')
            {
                c = getchar();
                continue;
            }
            if (c == '-')
            {
                s += c;
                c = getchar();
                continue;
            }
            if (!f)
            {
                if (c == '0')
                {
                    c = getchar();
                    continue;
                }
                f = true;
            }
            s += c;
            c = getchar();
        }
        if (s == "-"||s == "")
            s = "0";
        //cout<<s<<endl;
        //str[i] = s;
        q.add(s);
    }
    if(q.size()>2)cout<<f<<endl;
    else cout<<"no"<<endl;
    return 0;
}
*/
