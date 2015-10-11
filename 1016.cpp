#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
vector<int> sit[2];
bool comp(const int& a, const int& b)
{
	return sit[0][a] < sit[0][b];
}
int main()
{
	int x;
	for (int c = 1;; c++)
	{
		int ans = 0;
		cin >> x;
		if (x == 0) return 0;
		sit[0].clear();
		sit[0].resize(x);
		sit[1].clear();
		sit[1].resize(x);
		for (int i = 0; i < x; i++)
		{
			cin >> sit[0][i];
			sit[1][i] = i;
		}
		sort(sit[1].begin(), sit[1].end(), comp);
		int sitzero = sit[1][0];
		for (int i = 0; i < x; i++)
		{
			if (sit[1][i] < 0 || sit[1][i] == i) continue;
			int current = i;
			int cyclesize = 0;
			int minnum = sit[0][current];
			while (sit[1][current] >= 0)
			{
				ans += sit[0][current];
				if (sit[0][current] < minnum)
				{
					minnum = sit[0][current];
				}
				int t = current;
				current = sit[1][current];
				sit[1][t] = -1;
				cyclesize++;
			}
			ans -= minnum;
			ans += min(minnum*(cyclesize - 1), 2 * (minnum + sit[0][sitzero]) + sit[0][sitzero] * (cyclesize - 1));
		}
		cout << "Case " << c << ": " << ans << endl << endl;
	}
}