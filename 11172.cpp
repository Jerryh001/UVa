#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b,x;
    cin>>x;
    while(x--)
    {
        cin>>a>>b;
        if(a>b)
        {
            cout<<">"<<endl;
        }
        else if(a<b)
        {
            cout<<"<"<<endl;
        }
        else
        {
            cout<<"="<<endl;
        }
    }
}
