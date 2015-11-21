#include<climits>
#include<iostream>
#include<vector>
using namespace std;
int martix[10][2];
int map[10][10];
int mink[10][10];
void output(const int& l,const int& r)
{
	if (l == r)
	{
		cout << "A" << l + 1;
	}
	else
	{
		cout << "(";
		output(l,mink[l][r]);
		cout << " x ";
		output(mink[l][r]+1,r);
		cout << ")";
	}
}
int main()
{
	int n,temp;
	for (int x = 1;;x++)
	{
		cin >> n;
		if (!n) return 0;
		for (int i = 0; i < n; i++)
		{
			cin >> martix[i][0] >> martix[i][1];
		}
		for (int i = n-1; i >=0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					map[i][j] = 0;
				}
				else
				{
					map[i][j] = INT_MAX;
					for (int k = i; k < j; k++)
					{
						temp = map[i][k] + map[k + 1][j] + martix[i][0] * martix[k][1] * martix[j][1];
						if (temp < map[i][j])
						{
							map[i][j] = temp;
							mink[i][j] = k;
						}
					}
				}
			}
		}
		cout << "Case " << x << ": ";
		output(0, n - 1);
		cout << endl;
	}
}