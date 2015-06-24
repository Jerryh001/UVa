#include<iostream>
using namespace std;
int main()
{

    int n,length;
    cin>>n;
    cin.get();
    for(;n>0;n--)
    {
        char test[129];
        int ans[129]={0};
        for(length=0;;length++)
        {
            cin.get(test[length]);
            ans[length]=1;
            if(test[length]=='\n')
            {
                break;
            }
        }
        if(length==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        for(int i=0;i<length;i++)
        {
            switch(test[i])
            {
            case ']':
                for(int j=i-1;j>=0;j--)
                {
                    if(test[j]=='['&&ans[j]==1)
                    {
                        ans[i]=0;
                        ans[j]=0;
                        break;
                    }else if(ans[j]==1)
                    {
                        break;
                    }
                }
                break;
            case ')':
                for(int j=i-1;j>=0;j--)
                {
                    if(test[j]=='('&&ans[j]==1)
                    {
                        ans[i]=0;
                        ans[j]=0;
                        break;
                    }else if(ans[j]==1)
                    {
                        break;
                    }
                }
                break;
                default:{}
            }
        }
        int notans=0;
        for(int i=0;i<length;i++)
        {
            if(ans[i]==1)
            {
                notans=1;
                break;
            }
        }
        if(notans)
        {
            cout<<"No"<<endl;
        }else
        {
            cout<<"Yes"<<endl;
        }
    }
}
