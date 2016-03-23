#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}
	return a.second < b.second;
}
pair<int, int> ans[128];
string input;
int main()
{
	int n = 0;
	while (getline(cin, input))
	{
		if (n != 0)
		{
			cout << endl;
		}
		n++;
		for (int i = 32; i < 128; i++)
		{
			ans[i].first = i;
			ans[i].second = 0;
		}
		for (int i = 0; i < input.size(); i++)
		{
			ans[input[i]].second++;
		}
		sort(ans + 32, ans + 128, comp);
		for (int i = 32; i < 128; i++)
		{
			if (ans[i].second == 0) continue;
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
}