#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int sl;
    bool inq=false;
    while(1)
    {
        getline(cin,s);
        if(cin.eof()) return 0;
        sl=s.length();
        for(int i=0;i<sl;i++)
        {
            if(s[i]=='\"')
            {
                if(inq)
                {
                    cout<<"\'\'";
                }else
                {
                    cout<<"``";
                }
                inq=!inq;
            }else
            {
                cout<<s[i];
            }
        }
        cout<<endl;
    }
}
