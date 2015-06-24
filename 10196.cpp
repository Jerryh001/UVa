#include<iostream>
#include<cctype>
using namespace std;
void pmove(int,int,int);
void rmove(int,int,int);
void bmove(int,int,int);
void qmove(int,int,int);
void kmove(int,int,int);
void nmove(int,int,int);
char pad[8][8];
char sidename[3][6]={"no","white","black"};
int winside=0;
int main()
{
    int counttimes=0;
    while(1)
    {
        counttimes++;
        winside=0;
        int END=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin>>pad[i][j];
                if(pad[i][j]!='.')
                {
                    END=0;
                }
            }
        }
        if(END) return 0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(winside!=0) break;
                if(pad[i][j]!='.')
                {
                    int side;
                    if(islower(pad[i][j]))
                    {
                        side=0;
                    }else
                    {
                        side=1;
                    }
                    switch(tolower(pad[i][j]))
                    {
                        case 'p':
                            pmove(side,i,j);
                            break;
                        case 'r':
                            rmove(side,i,j);
                            break;
                        case 'b':
                            bmove(side,i,j);
                            break;
                        case 'q':
                            qmove(side,i,j);
                            break;
                        case 'k':
                            kmove(side,i,j);
                            break;
                        case 'n':
                            nmove(side,i,j);
                    }
                }
            }
        }
        cout<<"Game #"<<counttimes<<": "<<sidename[winside]<<" king is in check."<<endl;
    }
}
void pmove(int side,int i,int j)
{
    char target='K'+('k'-'K')*side;
    int way[2][2]={{i+1-2*side,j-1},{i+1-2*side,j+1}};
    for(int a=0;a<2;a++)
    {
        if(way[a][0]<8&&way[a][0]>=0&&way[a][1]<8&&way[a][1]>=0&&pad[way[a][0]][way[a][1]]==target)
        {
            winside=side+1;
        }
    }
}
void rmove(int side,int i,int j)
{
    char target='K'+('k'-'K')*side;
    int way[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int a=0;a<4;a++)
    {
        for(int c=1;i+way[a][0]*c>=0&&i+way[a][0]*c<8&&j+way[a][1]*c>=0&&j+way[a][1]*c<8;c++)
        {
            if(pad[i+way[a][0]*c][j+way[a][1]*c]==target)
            {
                winside=side+1;
                return;
            }else if(pad[i+way[a][0]*c][j+way[a][1]*c]!='.')
            {
                break;
            }
        }
    }
}
void bmove(int side,int i,int j)
{
    char target='K'+('k'-'K')*side;
    int way[4][2]={{1,1},{-1,-1},{-1,1},{1,-1}};
    for(int a=0;a<4;a++)
    {
        for(int c=1;i+way[a][0]*c>=0&&i+way[a][0]*c<8&&j+way[a][1]*c>=0&&j+way[a][1]*c<8;c++)
        {
            if(pad[i+way[a][0]*c][j+way[a][1]*c]==target)
            {
                winside=side+1;
                return;
            }else if(pad[i+way[a][0]*c][j+way[a][1]*c]!='.')
            {
                break;
            }
        }
    }
}
void qmove(int side,int i,int j)
{
    char target='K'+('k'-'K')*side;
    int way[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    for(int a=0;a<8;a++)
    {
        for(int c=1;i+way[a][0]*c>=0&&i+way[a][0]*c<8&&j+way[a][1]*c>=0&&j+way[a][1]*c<8;c++)
        {
            if(pad[i+way[a][0]*c][j+way[a][1]*c]==target)
            {
                winside=side+1;
                return;
            }else if(pad[i+way[a][0]*c][j+way[a][1]*c]!='.')
            {
                break;
            }
        }
    }
}
void kmove(int side,int i,int j)
{
    char target='K'+('k'-'K')*side;
    int way[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    for(int a=0;a<8;a++)
    {
        if(i+way[a][0]>=0&&i+way[a][0]<8&&j+way[a][1]>=0&&j+way[a][1]<8)
        {
            if(pad[i+way[a][0]][j+way[a][1]]==target)
            {
                winside=side+1;
                return;
            }
        }
    }
}
void nmove(int side,int i,int j)
{
    char target='K'+('k'-'K')*side;
    int way[8][2]={{2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2},{-2,-1},{-1,-2}};
    for(int a=0;a<8;a++)
    {
        if(i+way[a][0]>=0&&i+way[a][0]<8&&j+way[a][1]>=0&&j+way[a][1]<8)
        {
            if(pad[i+way[a][0]][j+way[a][1]]==target)
            {
                winside=side+1;
                return;
            }
        }
    }
}
