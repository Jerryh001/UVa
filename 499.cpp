#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
int main()
{
	string s;
	map<char, int> m;
	while (1)
	{
		m.clear();
		getline(cin, s);
		if (cin.eof())return 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]))
			{
				m[s[i]]++;
			}
		}
		int maxnum = 0;
		for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			if (it->second > maxnum)
			{
				maxnum = it->second;
			}
		}
		for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			if (it->second == maxnum)
			{
				cout << it->first;
			}
		}
		cout << " " << maxnum << endl;
	}
}