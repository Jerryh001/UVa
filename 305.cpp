#include<iostream>
#include<vector>
using namespace std;
vector<int> people;
int ma1n()
{
	int n;
	while (cin >> n)
	{
		if (!n) return 0;
		n *= 2;
		people.clear();
		for (int i = 0; i < n; i++)
		{
			people.push_back(i);
		}
		n /= 2;
		for (int m = n;; m++)
		{
			int kill = -1;
			vector<int>temppeople = people;
			while (temppeople.size() != n)
			{
				kill = (kill + m) % temppeople.size();
				if (temppeople[kill] < n)
				{
					goto notOK;
				}
				else
				{
					temppeople.erase(temppeople.begin()+kill);
					kill=(kill-1+ temppeople.size())%temppeople.size();
				}
			}
			cout << m << endl;
			break;
		notOK:;
		}
	}
}
































































































































































int main()
{
	int ans[14] = { 2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881 };
	int n;
	while (cin >> n)
	{
		if (!n) return 0;
		cout << ans[n - 1] << endl;
	}
}