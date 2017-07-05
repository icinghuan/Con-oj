#include<iostream>
#include<cstring>
using namespace std;

int pp(int);
char c[300];
int l;

//http://blog.csdn.net/dreamchaseryx/article/details/41213459

int pp(int pos)
{
    int i;
    i = pos + 1;
    while (1)
    {
        while (c[i] != '(' && c[i] != ')' && c[i] != 0)
            i++;
        if (c[i] == '(')
        {
            i = pp(i);
        }
        else if (c[i] == ')')
        {
            c[pos] = ' ';
            c[i] = ' ';
            return i + 1;
        }
        else
        {
            c[pos] = '$';
            return l;
        }
    }
}


int main()
{

    while (cin.getline(c, 120))
    {
        cout<<c<<endl;
        l = strlen(c);
        int i;
        for (i = 0; i < l; i++)
            if (c[i] != '(' && c[i] != ')')
                c[i] = ' ';
        i = 0;
        while (c[i] != 0)
        {
            while (c[i] != '(' && c[i] != 0)
                i++;
            if (c[i] == '(')
                i = pp(i);
        }
        i = 0;
        while (c[i] != 0)
        {
            if (c[i] == ')')
                c[i] = '?';
            i++;
        }
        cout << c << endl;
    }
    return 0;
}
