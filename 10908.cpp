#include<iostream>
using namespace std;
bool isok(int,int,int,int);
int main()
{
    int ways[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
    int ways2[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
    int n;
    cin>>n;
    for(;n>0;n--)
    {
        int m,n,q;
        cin>>m>>n>>q;
        char map[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
            }
        }
        cout<<m<<" "<<n<<" "<<q<<endl;
        for(int i=0;i<q;i++)
        {
            int a,b,lecount=0;
            cin>>a>>b;
            char center=map[a][b];
            int end=0;
            int l=0;
            for(;!end;l++)
            {
                for(int j=0;(!end)&&j<=l*2;j++)
                {
                    for(int k=0;(!end)&&k<4;k++)
                    {
                        if((!isok(a+l*ways[k][0]+j*ways2[k][0],b+l*ways[k][1]+j*ways2[k][1],m,n))||map[a+l*ways[k][0]+j*ways2[k][0]][b+l*ways[k][1]+j*ways2[k][1]]!=center)
                        {
                            end=1;
                            lecount=l;
                            break;
                        }
                    }
                }
            }
            cout<<lecount*2-1<<endl;
        }
    }
}
bool isok(int y,int x,int a,int b)
{
    return y>=0&&x>=0&&y<a&&x<b;
}
