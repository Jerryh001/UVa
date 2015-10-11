#include<iostream>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;

bool compare(const pair<char, int>& a,const pair<char, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}
vector< pair<char, int> > table;
int main()
{
	table.reserve(26);
	for (int i = 0; i < 26; i++)
	{
		table.push_back({'A' + i, 0});
	}
	int x;
	char c;
	cin >> x;
	cin.get();
	while (x)
	{
		cin.get(c);
		if (c=='\n') x--;
		if (isalpha(c))
		{
			table[toupper(c)-'A'].second++;
		}
	}
	sort(table.begin(), table.end(), compare);
	for (vector< pair<char, int> >::iterator i = table.begin(); i != table.end(); i++)
	{
		if (i->second == 0) break;
		cout << i->first << " " << i->second << endl;
	}
}