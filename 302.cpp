#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct street
{
	int number;
	int dest;
};
vector<street> map[45];
vector<bool> visited;
vector<int> route;
int streetcount = 0;
int start = 0;
void dfs(const int& node)
{
	int size = map[node].size();
	for (int i = 0; i < size; i++)
	{
		if (visited[map[node][i].number] == false)
		{
			visited[map[node][i].number] = true;
			dfs(map[node][i].dest);
			route.push_back(map[node][i].number);
		}
	}
}
int main()
{
	int x, y, z;
	while (1)
	{
		route.clear();
		streetcount = 0;
		for (int i = 1; i <= 44; i++)
		{
			map[i].clear();
		}
		while (1)
		{
			cin >> x >> y;
			if (x == 0 && y == 0)
			{
				if (streetcount == 0)
				{
					return 0;
				}
				else
				{
					break;
				}
			}
			cin >> z;
			if (streetcount == 0)
			{
				start = min(x, y);
			}
			map[x].push_back({ z,y });
			map[y].push_back({ z,x });
			streetcount++;
		}
		for (int i = 1; i <= 44; i++)
		{
			int deg = map[i].size();
			if (deg % 2 == 1)
			{
				goto fail;
			}
			sort(map[i].begin(), map[i].end(), [](const street& a, const street& b)
			{
				if (a.number == b.number)
				{
					return a.dest < b.dest;
				}
				return a.number < b.number;
			});
		}
		visited.clear();
		visited.resize(streetcount + 1, false);
		dfs(start);
		if (route.size()==streetcount)
		{
			for (int i = streetcount - 1; i >0; i--)
			{
				cout << route[i] << " ";
			}
			cout << route[0] << endl;
		}
		else
		{
			fail:
			cout << "Round trip does not exist." << endl;
		}
		cout << endl;
	}
}