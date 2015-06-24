#include<iostream>
using namespace std;
void left2(char);
int main()
{
    while(1)
    {
        char x;
        cin.get(x);
        if(cin.eof()) break;
        left2(tolower(x));

    }
    //cout<<endl;
}
void left2(char x)
{
    if(x=='\n'||x==' ')
    {
        cout<<x;
        return;
    }
    char alpha[26]={'d','m','b','g','t','h','j','k','p','l',';','\'','.',',','[',']','e','y','f','u','o','n','r','v','i','c'};
    for(int i=0;i<26;i++)
    {
        if(x==alpha[i])
        {
            cout<<char('a'+i);
            return;
        }
    }
    return;
}
