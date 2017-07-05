#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        int ma = 0;
        char ans;
        for (int i = 0; i < s.length()-1; ++i)
        {
            int k = 1;
            if ((i + k) < s.length()&&s[i] == s[i+k])
            {
                while ((i + k) < s.length()&&s[i] == s[i+k])
                {
                    k++;
                }
            }
            if (k > ma)
                {
                    ma = k;
                    ans = s[i];
                }
        }
        cout<<ans<<" "<<ma<<endl;
    }
    return 0;
}
