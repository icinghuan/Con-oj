#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

int random(int x)
{
	//srand((int)time(0));
	return rand()%x;
}

class Team
{
public:
	string name;
	int st=10;//实力
	int sp=2;//运气
	int sa=3;//稳定
	int sf=1;//绝对运气
    int win=0;
    int lose=0;
	int power() {return sa<=st/3?st+sp/2+sa/3+sf:st+sp/2-sa/3+sf;};
	int t_power() {return random(100)>sf?st+random(sp)-sa+random(2*sa):st*100;};

private:

};

class Game
{
public:
	Team T[16];
	int match[60][8][2];
	Game();
	void mk_mat();
	bool play(int a,int b);
    void normal();
    void _sort();
private:
};

void Game::_sort()
{
    int sort_T[16];
    for (int i=0;i<16;++i)
        sort_T[i]=i;
    int a,b,tmp;
    for (int i=0;i<16;++i)
        for (int j=0;j<15;++j)
        {
            a=sort_T[j];
            b=sort_T[j+1];
            if (T[a].win<T[b].win)
            {
                tmp=sort_T[j];
                sort_T[j]=sort_T[j+1];
                sort_T[j+1]=tmp;
            }
        }
    for (int i=0;i<16;++i)
        cout<<T[sort_T[i]].name<<" : "<<T[sort_T[i]].win<<endl;
    
}

Game::Game()
{
    //[West]
    T[0].name="HY";T[1].name="JNH";T[2].name="HM";T[3].name="PB";
    T[4].name="KH";T[5].name="HKS";T[6].name="C";T[7].name="DX";
    //[East]
    T[8].name="ACE";T[9].name="LT";T[10].name="TY";T[11].name="LJ";
    T[12].name="TH";T[13].name="HX";T[14].name="LF";T[15].name="AB";
}

bool Game::play(int a,int b)
{
    int t_a,t_b;
    t_a=T[a].t_power();
	t_b=T[b].t_power();
	while (t_a==t_b)
    {
        t_a=T[a].t_power();
	    t_b=T[b].t_power();
    }
    return t_a>t_b?true:false;
}

void Game::normal()
{
    mk_mat();
    int a,b;
    for (int i=0;i<60;++i)
        for (int j=0;j<8;++j)
        {
            a=match[i][j][0];
            b=match[i][j][1];
            if (play(a,b))
            {
                T[a].win++;
                if (random(2)==0)
                    T[a].st++;T[a].sp++;T[a].sa++;
                T[b].lose++;
            }
            else
            {
                T[a].lose++;
                T[b].win++;
                if (random(2)==0)
                    T[b].st++;T[b].sp++;T[b].sa++;
            }
        }
}

void Game::mk_mat()
{
    int k[8][2],temp;
    for (int i=0;i<8;++i)
    {
        k[i][0]=i;
        k[i][1]=15-i;
    }
    for (int i=0;i<60;++i)
    {
        for (int j=0;j<8;++j)
        {
            match[i][j][0]=k[j][0];
            match[i][j][1]=k[j][1];
        }
        temp=k[1][0];
        k[1][0]=k[0][1];
        for (int j=0;j<7;++j)
            k[j][1]=k[j+1][1];
        k[7][1]=k[7][0];
        for (int j=7;j>2;--j)
            k[j][0]=k[j-1][0];
        k[2][0]=temp;
    }
}

int main()
{
    srand((int)time(0));
    Game G;
    G.normal();
    for (int i=0;i<16;++i)
        cout<<G.T[i].name<<" : "<<G.T[i].win<<endl;
    cout<<endl;
    G._sort();
	return 0;
}
