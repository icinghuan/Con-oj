#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

const int MAXN = 1005;
struct bign{
    int n[MAXN],l;
    bign(char*S){for(int i=(l=strlen(S))-1;~i;--i)n[i]=S[l-i-1]-'0';}
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
    for(int i=x.l;i;out<<x.n[--i]);
    return out;
}

bign s1,s2,s3;

int main()
{
	int T,cas = 1;
	cin>>T;
	while (T--)
	{
		cin>>s2;
		cin>>s3;
		s1 = s2+s3;
		cout<<"Case "<<cas++<<":"<<endl;
		cout<<s2<<" + "<<s3<<" = "<<s1<<endl;
		if (T)
            cout<<endl;
	}
	return 0;
}
