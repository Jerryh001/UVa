#include<iostream>
#include<algorithm>
#include<sstream>
#include<fstream>
using namespace std;
int people[1000];
int main()
{
	//ofstream cout("out.txt");
	int n, x;
	cin >> n;
	int case1, case2;
	while (n--)
	{
		stringstream sout;
		cin >> x;
		for (int i = 0; i < x; i++)
		{
			cin >> people[i];
		}
		sort(people, people + x);
		int i = x-1;
		int ans = 0;
		for (; i >=4;)
		{
			case1 = people[0] * 2 + people[i-1] + people[i];
			case2 = people[0] + people[1] * 2 + people[i];
			if (case1 < case2)
			{
				sout << people[0] << " " << people[i-1] << endl;
				sout << people[0] << endl;
				sout << people[0] << " " << people[i] << endl;
				sout << people[0] << endl;
				ans += case1;
			}
			else
			{
				sout << people[0] << " " << people[1] << endl;
				sout << people[0] << endl;
				sout << people[i-1] << " " << people[i] << endl;
				sout << people[1] << endl;
				ans += case2;
			}
			i -= 2;
		}
		switch (i+1)
		{
		case 4:
			case1 = people[0] * 2 + people[i - 2] + people[i - 1] + people[i];
			case2 = people[0] + people[1] * 3 + people[i];
			if (case1 < case2)
			{
				sout << people[0] << " " << people[2] << endl;
				sout << people[0] << endl;
				sout << people[0] << " " << people[3] << endl;
				sout << people[0] << endl;
				sout << people[0] << " " << people[1] << endl;
				ans += case1;
			}
			else
			{
				sout << people[0] << " " << people[1] << endl;
				sout << people[0] << endl;
				sout << people[2] << " " << people[3] << endl;
				sout << people[1] << endl;
				sout << people[0] << " " << people[1] << endl;
				ans += case2;
			}
			break;
		case 3:
			case1 = people[0] + people[1] + people[2];
			sout << people[0] << " " << people[1] << endl;
			sout << people[0] << endl;
			sout << people[0] << " " << people[2] << endl;
			ans += case1;
			break;
		case 2:
			case1 = people[1];
			sout << people[0] << " " << people[1] << endl;
			ans += case1;
			break;
		case 1:
			case1 = people[0];
			sout << people[0] << endl;
			ans += case1;
			break;
		}
		
		cout << ans << endl;
		string temp;
		getline(sout, temp);
		while (!sout.eof())
		{
			
			cout << temp << endl;
			getline(sout, temp);
		}
		if (n) cout << endl;
	}
}