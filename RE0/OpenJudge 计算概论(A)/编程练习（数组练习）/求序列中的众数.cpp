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
        /*1.返回在字符串中首次出现的不匹配str中的任何一个字符的首字符索引, 从index开始搜索, 如果全部匹配则返回string::npos。
2.从index开始起搜索当前字符串, 查找其中与str前num个字符中的任意一个都不匹配的序列, 返回满足条件的第一个字符索引, 否则返回string::npos。
3.返回在当前字符串中第一个不匹配ch字符的索引, 从index开始搜索, 没用收获则返回string::npos。*/
        if(m==string::npos)
        /*npos 是一个常数，用来表示不存在的位置，类型一般是std::container_type::size_type 许多容器都提供这个东西。取值由实现决定，一般是-1，这样做，就不会存在移植的问题了。*/
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

//一直WA，以上是网上的标程，用到了map和一堆函数

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
