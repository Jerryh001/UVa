#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<"Case "<<i<<": ";
        if(x1+y1==x2+y2)
        {
            cout<<abs(y2-y1)<<endl;
        }else
        {
            cout<<abs(y1+x2+(x1+y1+x2+y2+2)*(x2+y2-x1-y1-1)/2+1)<<endl;
        }
    }
}
