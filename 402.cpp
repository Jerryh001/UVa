#include<iostream>
#include<vector>
using namespace std;
vector<int>people;
int main()
{
	int n,x,poker[20];
	int time = 1;
	while (cin >> n)
	{
		cin >> x;
		for (int i = 0; i < 20; i++)
		{
			cin >> poker[i];
		}

		people.resize(n);
		for (int i = 0; i < n; i++)
		{
			people[i] = i+1;
		}
		if (n <= x)
		{
			goto end;
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = poker[i]-1; j < people.size(); j += poker[i]-1)
			{
				people.erase(people.begin() + j);
				if (people.size() <= x)
				{
					goto end;
				}
			}
			if (people.size() <= x)
			{
				goto end;
			}
		}
	end:
		cout << "Selection #"<<time<<endl<<people[0];
		for (int i = 1; i < people.size(); i++)
		{
			cout << " " << people[i];
		}
		cout << endl << endl;
		time++;
	}
}