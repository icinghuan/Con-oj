#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>
#include <cstdlib>

using namespace std;

const int MAXN = 10005;
struct bign{
    int n[MAXN],l;
    bign(char*S){for(int i=(l=strlen(S))-1;~i;--i)n[i]=S[l-i-1]-'0';}
    bign(string S){for(int i=(l=S.length())-1;~i;--i)n[i]=S[l-i-1]-'0';}
    bign(int x=0){char S[20];sprintf(S,"%d",x);*this=bign(S);}
    void correct(){
        int carry=0;
        for(int i=0;i<l;++i){
            n[i]+=carry+10;
            carry=n[i]/10-1;
            n[i]%=10;
        }
        if(carry)n[l++]=carry;
        while(l-1&&!n[l-1])--l;
    }
};
typedef const bign& cbign;
bool compare(const int*a,const int*b,int l){
    for(int i=l-1;~i;--i)
        if(a[i]!=b[i])return a[i]<b[i];
    return false;
}
bool operator<(cbign a,cbign b){
    if(a.l!=b.l)return a.l<b.l;
    return compare(a.n,b.n,a.l);
}
bign operator+(cbign a,cbign b){
    if(a.l<b.l)return b+a;
    bign c(a);
    for(int i=0;i<b.l;++i)c.n[i]+=b.n[i];
    c.correct();
    return c;
}
bign operator-(cbign a,cbign b){
    bign c(a);
    for(int i=0;i<b.l;++i)c.n[i]-=b.n[i];
    c.correct();
    return c;
}
bign operator*(cbign a,cbign b){
    bign c;fill_n(c.n,c.l=a.l+b.l,0);
    for(int i=0;i<a.l;++i)
        for(int j=0;j<b.l;++j)
            c.n[i+j]+=a.n[i]*b.n[j];
    c.correct();
    return c;
}
bign divide(bign a,cbign b,int choice=0){///0.返回商 1.返回余数
    if(a<b)return choice?a:0;
    bign c;fill_n(c.n,c.l=a.l-b.l+1,0);
    for(int i=a.l-b.l;~i;--i){
        while(!compare(a.n+i,b.n,b.l)){
            for(int j=0;j<b.l;++j)
            if((a.n[i+j]-=b.n[j])<0){
                a.n[i+j]+=10;a.n[i+j+1]-=1;
            }
            ++c.n[i];
        }
        if(i+b.l-1)a.n[i+b.l-2]+=10*a.n[i+b.l-1];
    }
    c.correct();a.l=b.l;a.correct();
    return choice?a:c;
}
bign operator/(cbign a,cbign b){return divide(a,b);}
bign operator%(cbign a,cbign b){return divide(a,b,1);}
istream& operator>>(istream&in ,bign&x){
    char S[1000];
    in>>S;x=S;
    return in;
}
ostream& operator<<(ostream&out,const bign&x){
    bool flag = false;
    for(int i=x.l-1;i >= 0;--i)
    {
        if (flag)
        {
            out<<x.n[i];
        }
        else
        {
            if (x.n[i] != 0||i == 0)
            {
                flag = true;
                out<<x.n[i];
            }
        }

    }
    return out;
}

int sstoi(string s)
{
    int k = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        k = k*10+(int(s[i])-'0');
    }
    return k;
}

const bign mod = bign("1000000007");

int main()
{
    int T;
    char c;
    scanf("%d",&T);
    c = getchar();
    while (T--)
    {
        string s = "";
        c = getchar();
        while (c != '\n')
        {


        if (c == '(')
        {
            string s1 = "";
            c = getchar();
            while (c != ')')
            {
                s1 += c;
                c = getchar();
            }
            //cout<<s1<<endl;
            c = getchar();
            c = getchar();
            //string s2 = "";
            c = getchar();
            //while (c != ')')
            //{
             //   s2 += c;
              //  c = getchar();
            //}
            //cout<<s2<<endl;
            //cout<<sstoi(s2)<<endl;
            for (int i = 0; i < int(c)-'0'; ++i)
                s += s1;
            c = getchar();
        }
        else
        {
            s += c;
        }
        c = getchar();


        }
        //cout<<s<<endl;
        bign big = bign(s);
        //cout<<big<<endl;
        big = big%mod;
        cout<<big<<endl;
    }
    return 0;
}
