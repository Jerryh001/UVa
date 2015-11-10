#include<iostream>
#include<string>
#include<climits>
using namespace std;
string a, b;
struct item
{
	int step=-1;
	bool insert;
	bool delete2;
	bool replace;
};
item map[81][81];
int ans[160][3];
int anslen = 0;
int main()
{
	while (1)
	{
		getline(cin, a);
		getline(cin, b);
		if (cin.eof()) return 0;
		if (map[0][0].step == 0) cout << endl;
		anslen = 0;
		for (int i = 0; i <= a.length(); i++)
		{
			for (int j = 0; j <= b.length(); j++)
			{
				map[i][j].step = INT_MAX;
				map[i][j].insert = false;
				map[i][j].delete2 = false;
				map[i][j].replace = false;
			}
		}
		map[0][0].step = 0;
		for (int i = 0; i <= a.length(); i++)
		{
			for (int j = 0; j <= b.length(); j++)
			{
				if (j< b.length()&&map[i][j].step + 1 <= map[i][j+1].step)
				{
					if (map[i][j].step + 1 < map[i][j + 1].step)
					{
						map[i][j + 1].step = map[i][j].step + 1;
						map[i][j + 1].delete2 = false;
						map[i][j + 1].replace = false;
					}
					map[i][j + 1].insert = true;
				}
				if (i<a.length()&&map[i][j].step + 1 <= map[i+1][j].step)
				{
					if (map[i][j].step + 1 < map[i + 1][j].step)
					{
						map[i + 1][j].step = map[i][j].step + 1;
						map[i + 1][j].insert = false;
						map[i + 1][j].replace = false;
					}
					map[i + 1][j].delete2 = true;
				}
				if (i<a.length() && j< b.length() && map[i][j].step + (a[i] == b[j] ? 0 : 1) <= map[i+1][j+1].step)
				{
					if (map[i][j].step + (a[i] == b[j] ? 0 : 1) < map[i + 1][j + 1].step)
					{
						map[i + 1][j + 1].step = map[i][j].step + (a[i] == b[j] ? 0 : 1);
						map[i + 1][j + 1].insert = false;
						map[i + 1][j + 1].delete2 = false;
					}
					map[i + 1][j + 1].replace = true;
				}
			}
		}
		int ci = a.length(), cj = b.length();
		while (ci + cj != 0)
		{
			if (ci>0&&cj>0&&map[ci][cj].replace)
			{
				if (map[ci - 1][cj - 1].step <= map[ci][cj].step)
				{
					if (map[ci - 1][cj - 1].step < map[ci][cj].step)
					{
						ans[anslen][0] = ci;
						ans[anslen][1] = cj;
						ans[anslen][2] = 3;
						anslen++;
					}
					ci--;
					cj--;
				}
			}else if (cj>0&&map[ci][cj].insert)
			{
				if (map[ci][cj-1].step <= map[ci][cj].step)
				{
					if (map[ci][cj-1].step < map[ci][cj].step)
					{
						ans[anslen][0] = ci;
						ans[anslen][1] = cj;
						ans[anslen][2] = 1;
						anslen++;
					}
					cj--;
				}
			}else if (ci>0&&map[ci][cj].delete2)
			{
				if (map[ci-1][cj].step <= map[ci][cj].step)
				{
					if (map[ci-1][cj].step < map[ci][cj].step)
					{
						ans[anslen][0] = ci;
						ans[anslen][1] = cj;
						ans[anslen][2] = 2;
						anslen++;
					}
					ci--;
				}
			}
		}
		cout << map[a.length()][b.length()].step << endl;
		for (int i = anslen - 1; i >= 0; i--)
		{
			switch (ans[i][2])
			{
			case 1:
					cout << map[ans[i][0]][ans[i][1]].step << " Insert " << ans[i][1] << "," << b[ans[i][1] - 1] << endl;
				break;
			case 2:
				cout << map[ans[i][0]][ans[i][1]].step << " Delete " << ans[i][1] + 1 << endl;
				break;
			case 3:
				cout << map[ans[i][0]][ans[i][1]].step << " Replace " << ans[i][1] << "," << b[ans[i][1] - 1] << endl;
				break;
			}
		}
	}
}