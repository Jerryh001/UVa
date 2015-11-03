#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int main()
{
	vector<string> s;
	int n,x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		s.resize(x);
		for (int i = 0; i < x; i++)
		{
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		int ans = s.front().length();
		for (int i = 1; i < x; i++)
		{
			int j = 0;
			for (; j < s[i].length() && j < s[i - 1].length(); j++)
			{
				if (s[i][j] != s[i - 1][j])
				{
					break;
				}
			}
			ans += s[i].length() - j;
		}
		cout << ans << endl;
		for (int i = 0; i < x; i++)
		{
			cout << s[i] << endl;
		}
	}
}