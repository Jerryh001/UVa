#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    while(!cin.eof())
    {
        long long int d,s;
        cin>>s>>d;
        if(cin.eof()) return 0;
        d=(d+(s*(s-1))/2)*2;
        for(long long int x=sqrt(d);;x++)
        {
            if(x*(x+1)>=d)
            {
                cout<<x<<endl;
                break;
            }
        }
    }
}
