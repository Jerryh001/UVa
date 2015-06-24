#include<iostream>
//#include<fstream>
using namespace std;
int main()
{
    //ifstream cin("p7.txt");
    int n;
    cin>>n;
    for(;n>0;n--)
    {
        int day,partyn,ans=0;
        cin>>day>>partyn;
        int party[partyn];
        for(int i=0;i<partyn;i++)
        {
            cin>>party[i];
        }
        for(int i=1;i<=day;i++)
        {
            if(i%7==6||i%7==0)
            {
                continue;
            }
            for(int j=0;j<partyn;j++)
            {
                if(i%party[j]==0)
                {
                    //cout<<i<<endl;
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}
