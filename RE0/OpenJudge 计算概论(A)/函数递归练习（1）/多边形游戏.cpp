#include<bits/stdc++.h>
using namespace std;
#define add -1
#define mul -2
vector<int>v;
int ans=0;
void deb(vector<int>v){
for(int i=0;i<v.size();i++)
printf("%d%c",v[i]," \n"[i==v.size()-1]);
}
int dfs(int l,int r){
if(l==r)return v[l];
int ans=0;
for(int i=l+1;i<=r;i+=2){

if(v[i]==add){
ans=max(ans,dfs(l,i-1)+dfs(i+1,r));
}else{
ans=max(ans,dfs(l,i-1)*dfs(i+1,r));
}
}return ans;
}
int n;
int main(){
cin>>n;
for(int i=1;i<=n;i++){
int x;char c;
cin>>x;c=getchar();
while(c!='+'&&c!='*')c=getchar();
v.push_back(x);
if(c=='+')v.push_back(add);
else v.push_back(mul);
}int len=v.size();
for(int i=0;i<len;i++)v.push_back(v[i]);
//deb(v);
for(int i=0;i<len;i+=2){
ans=max(ans,dfs(i,i+len-2));
}cout<<ans<<endl;
return 0;
}
