#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int sl;
    while(1)
    {
        getline(cin,s);
        if(cin.eof()) return 0;
        sl=s.length();
        for(int i=0;i<sl;i++)
        {
            cout<<char(s[i]-7);
        }
        cout<<endl;
    }
}
