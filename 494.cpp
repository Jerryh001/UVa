#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string str;
    while(1)
    {
        getline(cin,str);
        if(cin.eof()) return 0;
        int strlen=str.length();
        int wordcount=0;
        bool isinword=false;
        for(int i=0;i<strlen;i++)
        {
            if(isalpha(str[i]))
            {
                if(isinword)
                {
                    if(i==strlen-1)
                    {
                        isinword=false;
                        wordcount++;
                    }
                }else
                {
                    isinword=true;
                }
            }else
            {
                if(isinword)
                {
                    isinword=false;
                    wordcount++;
                }
            }
        }
        cout<<wordcount<<endl;
    }
}
