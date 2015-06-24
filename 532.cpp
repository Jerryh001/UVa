#include<iostream>
using namespace std;
bool check(int,int,int);
int L,R,C;
int start[3],end_[3];
int ans=0;
int way[6][3]={{1,0,0},{0,1,0},{0,0,1},{0,0,-1},{0,-1,0},{-1,0,0}};
int main()
{
    while(1)
    {
        ans=0;
        cin>>L>>R>>C;
        if(!(L*R*C)) return 0;
        int map[L][R][C];
        char X;
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                for(int k=0;k<C;k++)
                {
                    cin>>X;
                    switch(X)
                    {
                        case '#':
                            map[i][j][k]=-1;
                            break;
                        case '.':
                            map[i][j][k]=0;
                            break;
                        case 'S':
                            map[i][j][k]=1;
                            start[0]=i;start[1]=j;start[2]=k;
                            break;
                        case 'E':
                            map[i][j][k]=0;
                            end_[0]=i;end_[1]=j;end_[2]=k;

                    }
                }
            }
        }
        int THEEND=0;
        for(int step=1;!THEEND;step++)
        {
            THEEND=1;
            for(int i=0;i<L;i++)
            {
                for(int j=0;j<R;j++)
                {
                    for(int k=0;k<C;k++)
                    {
                        if(map[i][j][k]==step)
                        {
                            for(int x=0;x<6;x++)
                            {
                                if(check(i+way[x][0],j+way[x][1],k+way[x][2])&&map[i+way[x][0]][j+way[x][1]][k+way[x][2]]==0)
                                {
                                    map[i+way[x][0]][j+way[x][1]][k+way[x][2]]=step+1;
                                    THEEND=0;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(!map[end_[0]][end_[1]][end_[2]])
        {
            cout<<"Trapped!"<<endl;
            //continue;
        }else
        {
            cout<<"Escaped in "<<map[end_[0]][end_[1]][end_[2]]-1<<" minute(s)."<<endl;
        }
    }
}
bool check(int x,int y,int z)
{
    return x<L&&x>=0&&y<R&&y>=0&&z<C&&z>=0;
}
