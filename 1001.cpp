#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct hole
{
	int x;
	int y;
	int z;
	int r;
	float dis;
	bool checked;
};
hole h[102];
float d(const hole& a, const hole& b)
{
	int deltax = a.x - b.x;
	int deltay = a.y - b.y;
	int deltaz = a.z - b.z;
	float ans = sqrt(deltax*deltax + deltay*deltay + deltaz*deltaz) - a.r - b.r;
	return ans < 0 ? 0:ans;
}
int main()
{
	int n;
	for (int turn = 1;;turn++)
	{
		cin >> n;
		if (n == -1) return 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> h[i].x >> h[i].y >> h[i].z >> h[i].r;
			h[i].dis = -1;
			h[i].checked = false;
		}
		cin >> h[0].x >> h[0].y >> h[0].z;
		h[0].r = 0;
		h[0].dis = 0;
		h[0].checked = false;
		cin >> h[n + 1].x >> h[n + 1].y >> h[n + 1].z;
		h[n + 1].r = 0;
		h[n + 1].dis = -1;
		h[n + 1].checked = false;
		int next = 0;
		while (h[n + 1].checked == false)
		{
			h[next].checked = true;
			for (int i = 1; i <= n + 1; i++)
			{
				if (i == next)
				{
					continue;
				}
				if (h[i].dis < 0 || d(h[next], h[i]) +h[next].dis< h[i].dis)
				{
					h[i].dis = d(h[next], h[i]) + h[next].dis;
				}
			}
			next = -1;
			for (int i = 1; i <= n + 1; i++)
			{
				if (h[i].checked == false && (next == -1 || h[i].dis <h[next].dis))
				{
					next = i;
				}
			}
		}
		printf("Cheese %d: Travel time = %.0f sec\n", turn, round(h[n + 1].dis * 10));
	}
}