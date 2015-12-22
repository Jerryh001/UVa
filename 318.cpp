#include<iostream>
#include<climits>
#include<cstdio>
#include<algorithm>
using namespace std;
struct domi
{
	int dis;
	bool checked;
};
struct edge
{
	int a;
	int b;
	int dis;
	float time;
};
int map[501][501];
domi v[501];
edge e[124751];
int main()
{
	int n, m;
	for (int time = 1;; time++)
	{
		cin >> n >> m;
		if (!(n | m)) return 0;
		if (m == 0)
		{
			printf("System #%d\nThe last domino falls after 0.0 seconds, at key domino 1.\n", time);
			cout << endl;
			continue;
		}
		for (int i = 0; i <= n; i++)
		{
			v[i].dis = -1;
			v[i].checked = true;
			for (int j = 0; j <= n; j++)
			{
				map[i][j] = -1;
			}
		}
		int next = 1;
		for (int i = 0; i < m; i++)
		{
			cin >> e[i].a >> e[i].b >> e[i].dis;
			map[e[i].a][e[i].b] = map[e[i].b][e[i].a] = e[i].dis;
			v[e[i].a].checked = false;
			v[e[i].b].checked = false;
		}
		v[1].dis = 0;

		while (next != -1)
		{
			v[next].checked = true;
			for (int i = 0; i <= n; i++)
			{
				if (v[i].checked==false&&map[next][i]>0 && (v[i].dis<0||v[next].dis + map[next][i] < v[i].dis))
				{
					v[i].dis = v[next].dis + map[next][i];
				}
			}
			next = -1;
			for (int i = 0; i <= n; i++)
			{
				if (v[i].checked == false&&v[i].dis>0 && (next == -1 || v[i].dis < v[next].dis))
				{
					next = i;
				}
			}
		}
		int maxedge = 0;
		for (int i = 0; i < m; i++)
		{
			int a = min(v[e[i].a].dis, v[e[i].b].dis);
			int b = max(v[e[i].a].dis, v[e[i].b].dis);
			if (b - a >= e[i].dis)
			{
				e[i].time = b;
			}
			else
			{
				e[i].time = (e[i].dis + v[e[i].a].dis + v[e[i].b].dis) / 2.0f;
			}
			if (e[i].time > e[maxedge].time)
			{
				maxedge = i;
			}
		}
		int maxv = 1;
		for (int i = 0; i <= n; i++)
		{
			if (v[i].dis>0&&v[i].dis > v[maxv].dis)
			{
				maxv = i;
			}
		}
		
		cout << "System #" << time << endl
			<< "The last domino falls after ";
		if(e[maxedge].time>v[maxv].dis)
		{
			printf("%.1f", e[maxedge].time);
			cout << " seconds, between key dominoes " << e[maxedge].a << " and " << e[maxedge].b << "." << endl;
		}
		else
		{
			printf("%.1f", v[maxv].dis + 0.0);
			cout << " seconds, at key domino " << maxv << "." << endl;
		}
		cout << endl;
	}
}