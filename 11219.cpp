#include<iostream>
using namespace std;
int main()
{
	int n,day1,mon1,year1,day2,mon2,year2;
	char trash;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>day1>>trash>>mon1>>trash>>year1;
		cin>>day2>>trash>>mon2>>trash>>year2;
		cout<<"Case #"<<i<<": ";
		int age=year1-year2;
		if(mon2>mon1||(mon2==mon1&&day2>day1))
		{
			age--;
		}
		if(age<0)
		{
			cout<<"Invalid birth date"<<endl;
		}
		else if(age>130)
		{
			cout<<"Check birth date"<<endl;
		}
		else
		{
			cout<<age<<endl;
		}
	}
}
