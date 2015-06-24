#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(;n>0;n--)
	{
		int x,ans=0;
		cin>>x;
		int score[x],sum=0;
		for(int i=0;i<x;i++)
		{
			cin>>score[i];
			sum+=score[i];
			score[i]*=x;
		}
		for(int i=0;i<x;i++)
		{
			if(score[i]>sum)
			{
				ans++;
			}
		}
		cout<<fixed<<setprecision(3)<<100.0*ans/x<<"%"<<endl;
	}
}