#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int Z=0;
    while(!cin.eof())
    {

        int n;
        int found=0;
        cin>>n;
        if(cin.eof()) return 0;
        if(Z==0)
        {
            Z++;
        }
        else
        {
            cout<<endl;
        }
        char roads[n][2][3];
        int mark[n];
        for(int i=0;i<n;i++)
        {
            cin>>roads[i][0]>>roads[i][1];
            mark[i]=-1;
        }
        char start[3],_end[3];
        cin>>start>>_end;
        /*if(!strcmp(start,_end))
        {
            for(int i=0;i<n;i++)
            {
                if(!strcmp(start,roads[i][0])||!strcmp(start,roads[i][1]))
                {
                    found=1;
                }
            }
            if(found)
            {
                cout<<start<<" "<<_end<<endl<<endl;
            }else
            {
                cout<<endl<<endl;
            }
            continue;
        }*/
        char crrpoint[3];
        strcpy(crrpoint,start);
        int crrid=0;
        int ansid=0;
        for(int p=0;p<n;p++)
        {
            if(!strcmp(roads[p][0],_end))
            {
                mark[p]=crrid;
            }
            else if(!strcmp(roads[p][1],_end))
            {
                mark[p]=crrid+100000;
            }
        }

        while(!found)
        {
            int finished=1;
            for(int p=0;p<n;p++)
            {
                if(mark[p]%100000==crrid)
                {
                    finished=0;
                    if(!strcmp(roads[p][1-mark[p]/100000],start)) found=1;
                    strcpy(crrpoint,roads[p][1-mark[p]/100000]);
                    for(int i=0;i<n;i++)
                    {
                        //cout<<i;
                        if(mark[i]<0&&!strcmp(roads[i][0],crrpoint))
                        {
                            mark[i]=crrid+1;
                        }
                        else if(mark[i]<0&&!strcmp(roads[i][1],crrpoint))
                        {
                            mark[i]=crrid+100001;
                        }
                    }
                }
            }
            /*cout<<"!"<<crrpoint<<endl;

            for(int i=0;i<n;i++)
            {
                cout<<mark[i]<<" ";
            }cout<<endl;*/
            if(finished) break;
            crrid++;
            //if(crrid>10) break;
        }

        if(!found)
        {
            cout<<"No route"<<endl;
        }else
        {
            strcpy(crrpoint,start);
            for(int i=crrid-1;i>=0;i--)
            {
                //cout<<i;
                for(int j=0;j<n;j++)
                {
                    if(mark[j]%100000==i&&!strcmp(roads[j][1-mark[j]/100000],crrpoint))
                    {
                        //cout<<j;
                        //cout<<" CRR0="<<crrpoint<<endl;
                        cout<<roads[j][1-mark[j]/100000]<<" "<<roads[j][mark[j]/100000]<<endl;
                        strcpy(crrpoint,roads[j][mark[j]/100000]);
                        //cout<<" CRR="<<crrpoint<<endl;
                        break;
                    }
                }
            }
        }

    }
}

