#include<iostream>
#include<climits>
using namespace std;
int map[51][51];
int sublength[51][51];
int cut[51];
int main()
{
	int l, n, temp;
	while (1)
	{
		cin >> l;
		if (!l) return 0;
		cin >> n;
		int start = 0;
		for (int i = 0; i < n; i++)
		{
			cut[i] = start;
			cin >> start;
			sublength[i][i] = cut[i] = start - cut[i];
		}
		sublength[n][n] = cut[n] = l - start;
		n++;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)
				{
					map[i][j] = 0;
				}
				else
				{
					map[i][j] = INT_MAX;
					sublength[i][j] = sublength[i][i] + sublength[i + 1][j];
					for (int k = i; k < j; k++)
					{
						temp = map[i][k] + map[k + 1][j] + sublength[i][k] + sublength[k + 1][j];
						if (temp < map[i][j])
						{
							map[i][j] = temp;
						}
					}
				}
			}
		}
		cout << "The minimum cutting is " << map[0][n - 1] << "." << endl;
	}
}