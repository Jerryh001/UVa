#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct lake
{
	int fish;
	int decrate;
	int timetonext;
};
int main()
{
	//ofstream cout("out.txt");
	vector<lake> map;
	int time=-1,n;
	vector<int> anslake;
	vector<int> roundfish;
	vector<int> roundlake;
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		if (time != -1)cout << endl;
		cin >> time;
		time *= 12;
		map.resize(n);
		anslake.clear();
		anslake.resize(n, 0);
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> map[i].fish;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> map[i].decrate;
		}
		for (int i = 0; i < n-1; i++)
		{
			cin >> map[i].timetonext;
		}
		for (int i = 0; i < n; i++)
		{
			int roundtime = time;
			int roundans = 0;
			for (int j = 0; j < i; j++)
			{
				roundtime -= map[j].timetonext;
			}
			if (roundtime <= 0) break;
			roundfish.resize(i + 1);
			roundlake.resize(i + 1);
			for (int j = 0; j <= i; j++)
			{
				roundfish[j] = map[j].fish;
				roundlake[j] = 0;
			}
			int choose = 0;
			while (roundtime)
			{
				choose = 0;
				for (int j = 0; j <= i; j++)
				{
					if (roundfish[choose] < roundfish[j]&& roundfish[j]>0)
					{
						choose = j;
					}
				}
				if (roundfish[choose] == 0)
				{
					roundlake[0] += roundtime;
					break;
				}
				roundans += roundfish[choose];
				roundfish[choose] -= map[choose].decrate;
				roundlake[choose]++;
				if (roundfish[choose] < 0)
				{
					roundfish[choose] = 0;
				}
				roundtime--;
			}
			if (roundans > ans)
			{
				ans = roundans;
				anslake = roundlake;
			}
		}
		for (int i = 0; i < anslake.size(); i++)
		{
			if (i != 0)
			{
				cout << ", ";
			}
			cout << anslake[i]*5;
		}
		for (int i = anslake.size(); i < n; i++)
		{
			if (i != 0)
			{
				cout << ", 0";
			}
		}
		cout << endl << "Number of fish expected: " << ans << endl;
	}
}
