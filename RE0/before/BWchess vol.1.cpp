#include<iostream>
#include<string>
#include<windows.h>
#include<cstdio>

using namespace std;

int temp_board[10000][8][8];
int temp_color[10000];

class Checkerboard
{
public:
    const int DIR[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int board[8][8];        //棋盘  1  白    -1  黑
    int black,white;        //黑子数，白子数
    Checkerboard()
    {
        init();
    };
    void init();      //棋盘初始化
    void change(int x,int y);       //棋局变化
    void print();       //打印棋盘
    bool judge(int x,int y,int color);      //评估下子是否可行
    bool check(int color);      //检测是否无子可下
    bool endgame();       //判断是否结束
};

class Chess:Checkerboard
{
public:
    void play();        //下棋
private:

    const int w1=0;
    const int w2=0;
    const int w3=0;
    const int w4=0;
    int evaluation(int k,int color);        //静态估值函数
    bool temp_judge(int k,int x,int y,int color);
    void temp_change(int k,int x,int y);
    void com(int &x,int &y,int color);
    void bfs(int &temp_evaluation,int color);
};

void Checkerboard::init()
{
    //初始化
    for(int i=0;i<=7;++i)
        for(int j=0;j<=7;++j)
            board[i][j]=0;
    board[3][3]=1;board[4][4]=1;white=2;
    board[3][4]=-1;board[4][3]=-1;black=2;
}

void Checkerboard::change(int x,int y)
{
    //棋局变化
    int temp_x,temp_y,x0,y0;
    for(int i=0;i<=7;++i)
        if ((x+DIR[i][0]>=0)&&(x+DIR[i][0]<=7)&&(y+DIR[i][1]>=0)&&(y+DIR[i][1]<=7)&&(board[x+DIR[i][0]][y+DIR[i][1]]==-board[x][y]))
        {
            temp_x=x;
            temp_y=y;
            while ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(board[temp_x+DIR[i][0]][temp_y+DIR[i][1]]==-board[x][y]))
            {
                temp_x=temp_x+DIR[i][0];
                temp_y=temp_y+DIR[i][1];
            }
            if ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(board[temp_x+DIR[i][0]][temp_y+DIR[i][1]]==board[x][y]))
            {
                temp_x=temp_x+DIR[i][0];temp_y=temp_y+DIR[i][1];
                x0=x+DIR[i][0];y0=y+DIR[i][1];
                while ((x0!=temp_x)||(y0!=temp_y))
                {
                    board[x0][y0]=board[x][y];
                    if (board[x][y]==1)
                    {
                        white++;
                        black--;
                    }
                    else
                    {
                        black++;
                        white--;
                    }
                    x0=x0+DIR[i][0];
                    y0=y0+DIR[i][1];
                }
            }
        }
}

void Checkerboard::print()
{
    //打印棋盘
    printf("  ");
    for (int i=1;i<=8;++i)
        printf("%d ",i);
    printf("\n");
    for(int i=0;i<=7;++i)
    {
        printf("%d ",i+1);
        for(int j=0;j<=7;++j)
            if (board[i][j]==0)
                printf("□");
            else
                if (board[i][j]==-1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x30);
                    printf("●");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3F);
                }
                else
                {
                    printf("●");
                }
        printf("\n");
    }
    printf("黑棋数： %d  ",black);
    printf("白棋数： %d\n\n",white);
}

bool Checkerboard::judge(int x,int y,int color)
{
    //评估下子是否可行
    if ((x<0)||(x>7)||(y<0)||(y>7)||(board[x][y]!=0)) return false;
    int temp_x,temp_y;
    for(int i=0;i<=7;++i)
        if ((x+DIR[i][0]>=0)&&(x+DIR[i][0]<=7)&&(y+DIR[i][1]>=0)&&(y+DIR[i][1]<=7)&&(board[x+DIR[i][0]][y+DIR[i][1]]==-color))
        {
            temp_x=x;
            temp_y=y;
            while ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(board[temp_x+DIR[i][0]][temp_y+DIR[i][1]]==-color))
            {
                temp_x=temp_x+DIR[i][0];
                temp_y=temp_y+DIR[i][1];
            }
            if ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(board[temp_x+DIR[i][0]][temp_y+DIR[i][1]]==color))
                return true;
        }
    return false;
}

bool Checkerboard::check(int color)
{
    //检测是否无子可下
    for(int i=0;i<=7;++i)
        for(int j=0;j<=7;++j)
            if (judge(i,j,color))
                return false;
    return true;
}

bool Checkerboard::endgame()
{
    //判断是否结束
    if ((black+white==64)||((check(-1))&&(check(1))))
        return true;
    else
        return false;
}

void Chess::play()
{
    //下棋
    system("color 3F");
    print();
    int x,y;
    cout<<"请选择执黑棋还是执白棋\n黑棋为 -1，白棋为 1，两电脑对下为 0，请输入数字poi~ ";
    int BWchoose;
    cin>>BWchoose;
    while ((BWchoose!=1)&&(BWchoose!=-1)&&(BWchoose!=0))
    {
        cout<<"黑棋为 -1，白棋为 1,两电脑对下为 0\n要输入 1, -1或者是 0哦poi~ ";
        cin>>BWchoose;
    }
    if (BWchoose==-1)
    {
        while (!endgame())
        {
            if (!check(-1))
            {
                cout<<"执 黑 ，请输入坐标poi~ ";
                cin>>x>>y;
                while (!judge(x-1,y-1,-1))
                {
                    cout<<"不能这么下哦poi~ ";
                    cin>>x>>y;
                }
                board[x-1][y-1]=-1;
                black++;
                change(x-1,y-1);
                print();
            }
            else
                cout<<"没办法下子了poi~"<<endl;
            if (!check(1))
            {
                com(x,y,1);
                board[x-1][y-1]=1;
                white++;
                change(x-1,y-1);
                cout<<"白子落子坐标poi~ "<<x<<' '<<y<<endl;
                print();
            }
            else
                cout<<"没办法下子了poi~"<<endl;
        }
    }
    else
    if (BWchoose==1)
    {
        while (!endgame())
        {
            if (!check(-1))
            {
                com(x,y,-1);
                board[x-1][y-1]=-1;
                black++;
                change(x-1,y-1);
                cout<<"黑子落子坐标poi~ "<<x<<' '<<y<<endl;
                print();
            }
            else
                cout<<"没办法下子了poi~"<<endl;
            if (!check(1))
            {
                cout<<"执 白 ，请输入坐标poi~ ";
                cin>>x>>y;
                while (!judge(x-1,y-1,1))
                {
                    cout<<"不能这么下哦poi~ ";
                    cin>>x>>y;
                }
                board[x-1][y-1]=1;
                white++;
                change(x-1,y-1);
                print();
            }
            else
                cout<<"没办法下子了poi~"<<endl;
        }
    }
    else
    {
        while (!endgame())
        {
            if (!check(-1))
            {
                com(x,y,-1);
                board[x-1][y-1]=-1;
                black++;
                change(x-1,y-1);
                cout<<"黑子落子坐标poi~ "<<x<<' '<<y<<endl;
                print();
            }
            else
                cout<<"没办法下子了poi~"<<endl;
            if (!check(1))
            {
                com(x,y,1);
                board[x-1][y-1]=1;
                white++;
                change(x-1,y-1);
                cout<<"白子落子坐标poi~ "<<x<<' '<<y<<endl;
                print();
            }
            else
                cout<<"没办法下子了poi~"<<endl;
        }
    }
    if (black>white)
        cout<<"黑子胜poi~"<<endl;
    else
        if (black<white)
            cout<<"白子胜poi~"<<endl;
        else
            cout<<"平局了poi~"<<endl;
}

int Chess::evaluation(int k,int color)
{
    const int value[8][8]={{110,-30,10,10,10,10,-30,110},
                        {-30,-110,5,5,5,5,-110,-30},
                        {10,5,1,1,1,1,5,10},
                        {10,5,1,1,1,1,5,10},
                        {10,5,1,1,1,1,5,10},
                        {10,5,1,1,1,1,5,10},
                        {-30,-110,5,5,5,5,-110,-30},
                        {110,-30,10,10,10,10,-30,110}};
    int total=0;
    for(int i=0;i<=7;++i)
        for(int j=0;j<=7;++j)
            if (temp_board[k][i][j]==color)
                total+=value[i][j];
            else
                if (temp_board[k][i][j]==-color)
                    total-=value[i][j];
    return total;
}

bool Chess::temp_judge(int k,int x,int y,int color)
{
    //评估下子是否可行
    if (temp_board[k][x][y]!=0) return false;
    int temp_x,temp_y;
    for(int i=0;i<=7;++i)
        if ((x+DIR[i][0]>=0)&&(x+DIR[i][0]<=7)&&(y+DIR[i][1]>=0)&&(y+DIR[i][1]<=7)&&(temp_board[k][x+DIR[i][0]][y+DIR[i][1]]==-color))
        {
            temp_x=x;
            temp_y=y;
            while ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(temp_board[k][temp_x+DIR[i][0]][temp_y+DIR[i][1]]==-color))
            {
                temp_x=temp_x+DIR[i][0];
                temp_y=temp_y+DIR[i][1];
            }
            if ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(temp_board[k][temp_x+DIR[i][0]][temp_y+DIR[i][1]]==color))
                return true;
        }
    return false;
}

void Chess::temp_change(int k,int x,int y)
{
    //棋局变化
    int temp_x,temp_y,x0,y0;
    for(int i=0;i<=7;++i)
        if ((x+DIR[i][0]>=0)&&(x+DIR[i][0]<=7)&&(y+DIR[i][1]>=0)&&(y+DIR[i][1]<=7)&&(temp_board[k][x+DIR[i][0]][y+DIR[i][1]]==-temp_board[k][x][y]))
        {
            temp_x=x;
            temp_y=y;
            while ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(temp_board[k][temp_x+DIR[i][0]][temp_y+DIR[i][1]]==-temp_board[k][x][y]))
            {
                temp_x=temp_x+DIR[i][0];
                temp_y=temp_y+DIR[i][1];
            }
            if ((temp_x+DIR[i][0]>=0)&&(temp_x+DIR[i][0]<=7)&&(temp_y+DIR[i][1]>=0)&&(temp_y+DIR[i][1]<=7)&&(temp_board[k][temp_x+DIR[i][0]][temp_y+DIR[i][1]]==temp_board[k][x][y]))
            {
                temp_x=temp_x+DIR[i][0];temp_y=temp_y+DIR[i][1];
                x0=x+DIR[i][0];y0=y+DIR[i][1];
                while ((x0!=temp_x)||(y0!=temp_y))
                {
                    temp_board[k][x0][y0]=temp_board[k][x][y];
                    x0=x0+DIR[i][0];
                    y0=y0+DIR[i][1];
                }
            }
        }
}

void Chess::com(int &x,int &y,int color)
{
    int maxevaluation=-10000;
    int temp_evaluation;
    for(int i=0;i<=7;++i)
        for(int j=0;j<=7;++j)
            if (judge(i,j,color))
            {
                for(int ii=0;ii<=7;++ii)
                    for(int jj=0;jj<=7;++jj)
                        temp_board[0][ii][jj]=board[ii][jj];
                temp_color[0]=-color;
                temp_board[0][i][j]=color;
                temp_change(0,i,j);
                temp_evaluation=evaluation(0,color);
                bfs(temp_evaluation,color);
                if (temp_evaluation>maxevaluation)
                {
                    maxevaluation=temp_evaluation;
                    x=i;
                    y=j;
                }
            }
    x++;
    y++;
}

void Chess::bfs(int &temp_evaluation,int color)
{
    int l=0,r=0;
    while ((l<=r)&&(r<10000))
    {
        for(int i=0;i<=7;++i)
            for(int j=0;j<=7;++j)
                if (temp_judge(l,i,j,temp_color[l]))
                {
                    r++;
                    for(int ii=0;ii<=7;++ii)
                        for(int jj=0;jj<=7;++jj)
                            temp_board[r][ii][jj]=temp_board[l][ii][jj];
                    temp_board[r][i][j]=color;
                    temp_change(r,i,j);
                    temp_evaluation+=evaluation(r,color);
                }
        l++;
    }
}

int main()
{
    char ch='y';
    while (1)
    {
        Chess BWChess;
        BWChess.play();
        printf("还要继续么poi~（y/n) ");
        cin>>ch;
        if (ch=='n')
            break;
    }
    return 0;
}
