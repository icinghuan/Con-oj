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
bign divide(bign a,cbign b,int choice=0){///0.·µ»ØÉÌ 1.·µ»ØÓàÊý
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

const bign mod = bign("1000000007");

template <class T>
void StackClear(stack<T> &s)          //清空栈
{
    while(!s.empty())
        s.pop();
}


/*
判断读取到的字符是否是运算符
*/
int IsOperator(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '=':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}


/*
比较前后两个运算符的优先级
(为了判断方便，增设一个等号“=”作为表达式的定界符)
oper1>=oper2返回1
oper1<oper2返回-1
oper1、oper2分别为左右括号返回0
*/
int Priority(char oper1,char oper2)
{
    int pri;
    switch(oper2)
    {
        case '+':
        case '-':
            if(oper1=='(' || oper1=='=')
                pri=-1;
            else
                pri=1;
            break;

        case '*':
        case '/':
            if(oper1=='*' || oper1=='/' || oper1==')')
                pri=1;
            else
                pri=-1;
            break;

        case '(':
            if(oper1==')')      //左括号右侧不能马上出现右括号
            {
                cout<<"表达式格式有误！\n";
                return 0;
            }
            else
                pri=-1;
            break;

        case ')':
            if(oper1=='(')
                pri=0;       //左右括号配对
            else
                pri=1;
            break;

        case '=':
            if(oper1=='(')
            {
                cout<<"括号不匹配\n";
                return 0;
            }
            else if(oper1=='=')
                pri=0;      //等号配对，返回0
            else
                pri=1;
            break;
    }
    return pri;
}


/*
根据运算符和两个操作数进行运算
*/
bign calculate(bign a,int oper,bign b)
{
    switch(oper)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
    }
}


/*
对多位数进行数值拼接
*/
bign NumberSplicing(char ch[])
{
    int dot = 0;    //是否遇到小数点的标志
    bign temp =0; //临时拼接的数值
    static int len = 10;

    for(int n=0;n<strlen(ch);n++)
    {
        char c = ch[n];
        if(c=='.')
        dot = 1;    //将标志设为1
        else
        {
            c-='0';     //先将相应的数字字符转换成整数
            if(dot==0)
                temp = temp *10 + c;
            else
            {
                temp = temp + c/len;  //小数点第一位的数x相当于 x/10;
                len *= 10;                    //小数点的第二位数相当于 x/100;
                //cout<<"数字转换中的暂存值："<<temp<<endl;
            }
        }

    }



    return temp;
}


/*
计算表达式的值：
初始化两个栈：一个操作数栈，一个运算符栈。

从左至右遍历每一个字符，遍历过程中遵循步骤和原则如下：
（1）遇到数字则直接压到数字栈顶。
（2）遇到运算符（+-* /）时，若操作符栈为空，则直接放到操作符栈顶，否则，见（3）。
（3）若操作符栈顶元素的优先级比当前运算符的优先级小，则直接压入栈顶，否则执行步骤（4）。
（4）弹出数字栈顶的两个数字并弹出操作符栈顶的运算符进行运算，把运算结果压入数字栈顶，重复（2）和（3）
     直到当前运算符被压入操作符栈顶。
（5）遇到左括号“（”时则直接压入操作符栈顶。
（6）遇到右括号“）”时则依次弹出操作符栈顶的运算符运算数字栈的最顶上两个数字，直到弹出的操作符为左括号。
*/
bign CalcExp(string express)
{
    bign a,b;             //两个操作数
    char opera;             //运算符
    char c;                 //字符变量
    char x;                 //x用来获取运算符栈栈顶的运算符
    stack<char> oper;
    stack<bign> data;   //运算符栈栈顶的运算符，操作数栈
    char tempNum[20];       //与多位数对应的字符数组
    int j=0;

    int i=0, flag=0;        //flag做标志，用来处理多位数

    oper.push('=');         //先将定界符(=)推入操作符栈

    c = express[i++];
    bign num = bign("0");

    while(c!='=' || x!='=')         //循环处理表达式中的每个字符
    {
        if(IsOperator(c))   //若是运算符
        {
            if(flag)        //将操作数入栈（因为读取到数字时，数字并没有及时进入数字栈）
            {
                tempNum[j]=0;
                j=0;
                num = NumberSplicing(tempNum);  //遇到操作符时，将数值拼接的结果返回回来
                //cout << "n----" << num << endl;
                data.push(num);         ///////////////////////////////////////////////////////////
                num = 0;                //入栈之后清空某一个操作数的暂存值
                flag = 0;               //且将标志置0，表示操作数已入栈
            }

            switch(Priority(x,c))
            {
                case -1:    //当前运算符c大于前一运算符x
                    //cout << "o----" << c << endl;
                    oper.push(c);       //当前运算符进栈/////////////////////////////////
                    c=express[i++];     //取表达式下一字符
                    break;

                case 0:                 //括号（等号）配对
                    oper.pop();         //运算符左半部分出栈（抛弃）
                    c=express[i++];     //取表达式下一字符
                    break;

                case 1:                     //当前运算符c小于等于前一运算符x
                    opera = oper.top();     //出栈之前取得栈顶元素
                    oper.pop();             //运算符出栈

                    b = data.top();
                    data.pop();
                    a = data.top();
                    data.pop();             //两个操作数出栈
                    bign t = calculate(a,opera,b);    //计算结果
                    data.push(t);       //将结算结果入栈
                    break;
            }
        }

        else if(c>='0' && c<='9' || c=='.')   //若输入的是数字字符(不入栈，因为可能是多位数字）
        {
            tempNum[j++] = c;
            flag = 1;               //设置操作数。表示操作数未入栈
            c=express[i++];
        }
        else
        {
            cout<<"输入有误\n";
            return 0;
        }

        x = oper.top();     //获取运算符栈顶的元素
        //cout<<"栈顶的操作符为："<<x<<endl;
    }

        num = data.top();

        StackClear(oper);
        StackClear(data);       //清空两个栈
        //cout<<num<<endl;

        return  num;    //返回数字栈栈顶元素，即为计算结果

    }


bign sstoi(string s)
{
    bign k = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        k = k*10+(int(s[i])-'0');
    }
    return k;
}

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
            string s2 = "";
            c = getchar();
            while (c != ')')
            {
                s2 += c;
                c = getchar();
            }
            //cout<<s2<<endl;
            //cout<<sstoi(s2)<<endl;
            for (int i = 0; i < sstoi(s2); ++i)
                s += s1;
        }
        else
        {
            s += c;
        }
        c = getchar();


        }
        //cout<<s<<endl;
        bool flag2 = false;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] < '0'||s[i] > '9')
                flag2 = true;
        bign big;
        if (flag2)
        {
            s += '=';
            big = CalcExp(s);
        }
        else
        {
            big = sstoi(s);
        }
        big = big%mod;
        cout<<big<<endl;

    }
    return 0;
}
