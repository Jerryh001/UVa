#include<algorithm>
#include<cmath>
#include<climits>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<vector>
using namespace std;
int change[4000];
vector<int> customer;
int main()
{
	for (int i = 0; i < 100; i++) //$2
	{
		for (int j = 0; j < 2; j++) //$1
		{
			for (int k = 0; k < 2; k++)//50c
			{
				for (int l = 0; l < 5; l++)//10c(with 20c)
				{
					for (int m = 0; m < 2; m++)//5c
					{
						change[m + l * 2 + k * 10 + j * 20 + i * 40] = m + l / 2 + l % 2 + k + j + i;
					}
				}
			}
		}
	}
	int a, b, c, d, e, f, m_int;
	float m;
	while (1)
	{
		cin >> a >> b >> c >> d >> e >> f;
		if (!(a | b | c | d | e | f)) return 0;
		cin >> m;
		m_int = round(m * 100) / 5;
		customer.clear();
		int range = a + b * 2 + c * 4 + d * 10 + e * 20 + f * 40 + 1;
		customer.resize(range, INT_MAX);
		customer[0] = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = range - 1; j >= 0; j--)
			{
				if (customer[j] != INT_MAX)
				{
					customer[j + 1] = min(customer[j + 1], customer[j] + 1);
				}
			}
		}
		for (int i = 0; i < b; i++)
		{
			for (int j = range - 1; j >= 0; j--)
			{
				if (customer[j] != INT_MAX)
				{
					customer[j + 2] = min(customer[j + 2], customer[j] + 1);
				}
			}
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = range - 1; j >= 0; j--)
			{
				if (customer[j] != INT_MAX)
				{
					customer[j + 4] = min(customer[j + 4], customer[j] + 1);
				}
			}
		}
		for (int i = 0; i < d; i++)
		{
			for (int j = range - 1; j >= 0; j--)
			{
				if (customer[j] != INT_MAX)
				{
					customer[j + 10] = min(customer[j + 10], customer[j] + 1);
				}
			}
		}
		for (int i = 0; i < e; i++)
		{
			for (int j = range - 1; j >= 0; j--)
			{
				if (customer[j] != INT_MAX)
				{
					customer[j + 20] = min(customer[j + 20], customer[j] + 1);
				}
			}
		}
		for (int i = 0; i < f; i++)
		{
			for (int j = range - 1; j >= 0; j--)
			{
				if (customer[j] != INT_MAX)
				{
					customer[j + 40] = min(customer[j + 40], customer[j] + 1);
				}
			}
		}
		int ans = INT_MAX;
		for (int i = m_int; i < range; i++)
		{
			if (customer[i] != INT_MAX)
			{
				ans = min(ans, customer[i] + change[i - m_int]);
			}
		}
		cout << setw(3) << ans << endl;
	}

}