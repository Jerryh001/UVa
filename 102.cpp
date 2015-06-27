#include<iostream>
#include<string>
using namespace std;
int main()
{
    int rawarr[3][3];
    int costarr[3][3];
    char order[3]={'B','G','C'};
    int redusedcst=0;
    int ans=-1;
    string ansorder;
    while(1)
    {
        redusedcst=0;
        ans=-1;
        ansorder[0]=4;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>rawarr[i][j];
            }
        }
        if(cin.eof()) return 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                costarr[i][j]=rawarr[(i+1)%3][j]+rawarr[(i+2)%3][j];
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==j) continue;
                for(int k=0;k<3;k++)
                {
                    if(k==j||k==i) continue;
                    int tempsum=costarr[0][i]+costarr[1][j]+costarr[2][k];
                    if(ans==-1||tempsum<=ans)
                    {
                        string tempstr="";
                        tempstr+=order[i];
                        tempstr+=order[j];
                        tempstr+=order[k];
                        if(ans==-1||tempsum<ans||tempstr.compare((ansorder))<0)
                        {
                            ansorder=tempstr;
                        }
                        ans=tempsum;
                    }
                }
            }
        }
        cout<<ansorder<<" "<<ans<<endl;
    }
}
