#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i=0;
    char arr[101][100]={'\0'};
    for(;!cin.eof();i++)
    {
        cin.getline(arr[i],101);
    }
    for(int j=0;j<100;j++)
    {
        char ans[101]={'\0'};
        int endline=1;
        for(int h=0;h<i-1;h++)
        {
            if(endline&&arr[h][j]=='\0')
            {
                continue;
            }else
            {
                if(arr[h][j]=='\0')
                arr[h][j]=' ';
                endline=0;
                ans[i-2-h]=arr[h][j];
            }
        }
        if(strlen(ans)==0) break;
        cout<<ans<<endl;
    }
}
