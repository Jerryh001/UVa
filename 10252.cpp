#include<iostream>
#include<string>
using namespace std;
int main()
{
    while(1)
    {
        string a,b;
        getline(cin,a);
        getline(cin,b);
        if(cin.eof()) return 0;
        int ans[26]={0};
        int space=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='@') continue;
            for(int j=0;j<b.length();j++)
            {
                if(a[i]==b[j])
                {
                    if(a[i]==' ')
                    {
                        space++;
                    }else
                    {
                        ans[a[i]-'a']++;
                    }
                    a[i]='@';
                    b[j]='@';
                }
            }
        }
        for(int j=0;j<space;j++)
        {
            cout<<' ';
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<ans[i];j++)
            {
                cout<<char(i+'a');
            }
        }
        cout<<endl;
    }
}
