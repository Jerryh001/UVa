#include<iostream>
#include<cmath>
using namespace std;
int sum(int);
int main()
{
    int pri[9592];
    int prinum=0;
    for(int i=2;i<100000;i++)
    {
        int _not=0;
        for(int j=2;j<i&&!_not;j++)
        {
            if(i%j==0) _not=1;
        }
        if(!_not)
        {
            pri[prinum]=i;
            prinum++;
        }
    }
    int n;
    cin>>n;
    for(;n>0;n--)
    {
        int k;
        cin>>k;
        k++;
        while(1)
        {
            int x=k;
            int sumx=sum(x);
            int sumdx=0;
            for(int i=0;i<prinum&&x>1;)
            {
                if(pri[i]==k)
                {
                    break;
                }
                if(x%pri[i]==0)
                {
                    sumdx+=sum(pri[i]);
                    x/=pri[i];
                    //cout<<pri[i]<<endl;
                }
                else
                {
                    i++;
                }
            }
            if(x!=k&&x!=1)
            {
                sumdx+=sum(x);
            }
            //cout<<sumx<<endl<<sumdx<<endl;break;
            if(sumx==sumdx)
            {
                break;
            }
            k++;
        }
        cout<<k<<endl;
    }
}
int sum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
