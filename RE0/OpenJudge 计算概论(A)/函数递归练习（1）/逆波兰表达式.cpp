#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

double n(){
    char str[20];
    cin>>str;
    switch(str[0]){
        case'+':return n()+n();
        case'-':return n()-n();
        case'*':return n()*n();
        case'/':return n()/n();
        default:return atof(str);
   }
}

int main()
{
    printf("%lf\n",n());
    return 0;
}
