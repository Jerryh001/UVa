#include<iostream>
#include<list>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
list<int> nib[101];
vector<int> visit;
void check(int i,const int& round)
{
	if (visit[i] != round)
	{
		visit[i] = round;		
		for (list<int>::iterator it = nib[i].begin(); it != (nib[i]).end(); it++)
		{
			check(*it, round);
		}
	}
}
int main()
{
	int n,in,in2;
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		int ans = 0;
		visit.clear();
		visit.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			nib[i].clear();
		}
		while (1)
		{
			cin >> in;
			if (in == 0) break;
			while (cin.get() != '\n')
			{
				cin >> in2;
				if (find(nib[in].begin(), nib[in].end(), in2) == nib[in].end())
				{
					nib[in].push_back(in2);
				}
				if (find(nib[in2].begin(), nib[in2].end(), in) == nib[in2].end())
				{
					nib[in2].push_back(in);
				}
				
			}
		}
		for (int i = 1; i <= n; i++)
		{
			visit[i] = i;
			check(i==1?2:1,i);
			for (int j = 1; j <= n; j++)
			{
				if (visit[j] != i)
				{
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}