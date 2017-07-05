#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string str[3];

int main()
{
    char c = getchar();
    int k = 0;
    while (c != '\n'&&c != EOF)
    {
        if (c == ',')
            k++;
        else
            str[k] += c;
        c = getchar();
    }
    int p1 = -1;
    int p2 = -1;
    for (int i = 0; i <= str[0].length()-str[1].length(); ++i)
        if (str[0].substr(i,str[1].length()) == str[1])
        {
            p1 = i+str[1].length();
            break;
        }
    for (int i = str[0].length()-str[2].length(); i >= 0; --i)
        if (str[0].substr(i,str[2].length()) == str[2])
        {
            p2 = i;
            break;
        }
    if (p1 == -1||p2 == -1)
        cout<<-1<<endl;
    else
        if (p1 > p2)
            cout<<-1<<endl;
        else
            cout<<p2-p1<<endl;
    return 0;
}
