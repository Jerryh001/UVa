#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector< pair<int, int> > stick;
vector< pair<int, int> > anslist;
bool ssort(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}
int main()
{
	int n, x;
	pair<int, int> in;
	cin >> n;
	while (n--)
	{
		stick.clear();
		anslist.clear();
		cin >> x;
		while (1)
		{
			cin >> in.first >> in.second;
			if (!(in.first | in.second)) break;
			stick.push_back(in);
		}
		sort(stick.begin(), stick.end(), ssort);
		int currentleft = 0;
		int currentstick = -1;
		for (int i = 0; i < stick.size(); i++)
		{
			if (currentleft > x)
			{
				break;
			}
			else if (stick[i].first > currentleft)
			{
				if (currentstick < 0)
				{
					anslist.clear();
					break;
				}
				currentstick = -1;
				currentleft = anslist.back().second;
				if (currentleft > x)
				{
					break;
				}
			}
			if (currentleft >= stick[i].first&&stick[i].second > currentleft)
			{
				if (currentstick < 0)
				{
					anslist.push_back(stick[i]);
				}
				else if (stick[i].second>anslist.back().second)
				{
					anslist.back() = stick[i];
				}
				currentstick = i;
			}
		}
		cout << anslist.size() << endl;
		for (int i = 0; i < anslist.size(); i++)
		{
			cout << anslist[i].first << " " << anslist[i].second << endl;
		}
		if (n)cout << endl;
	}
}