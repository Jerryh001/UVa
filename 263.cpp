#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    while(1)
    {
        int num;
        int ansarr[1000]={-1};
        cin>>num;
        if(num==0)
        {
            return 0;
        }
        ansarr[0]=num;
        cout<<"Original number was "<<num<<endl;
        int gotans=0;
        int times=1;
        for(;!gotans;times++)
        {
            char numarr1[12]={'\0'};
            int j=0;
            for(int i=1;ansarr[times-1]/i>0;i*=10,j++)
            {
                numarr1[j]=(ansarr[times-1]/i)%10+'0';
            }
            sort(numarr1,numarr1+j);
            int littlenum=atoi(numarr1);
            reverse(numarr1,numarr1+j);
            int bignum=atoi(numarr1);
            ansarr[times]=bignum-littlenum;
            cout<<bignum<<" - "<<littlenum<<" = "<<ansarr[times]<<endl;
            for(int i=0;i<times;i++)
            {
                if(ansarr[i]==ansarr[times])
                {
                    gotans=1;
                }
            }
        }
        cout<<"Chain length "<<times-1<<endl<<endl;
    }
}
