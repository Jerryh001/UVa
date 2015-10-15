#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
vector<int> pri;
bool ispri(const int& i)
{
	int sqrti = round(sqrt(i));
	for (int j = 0; j < pri.size()&&pri[j]<=sqrti; j++)
	{
		if (i%pri[j] == 0)
		{
			return false;
		}
	}
	/*for (int j = pri.back(); j <= sqrti; j++)
	{
		if (i%j == 0)
		{
			return false;
		}
	}*/
	return true;
}
int main()
{
	pri.push_back(2);
	for (int i = 3; i < 31630; i++)
	{
		if (ispri(i))
		{
			pri.push_back(i);
		}
	}
	int n;
	cin >> n;
	while (n--)
	{
		map<int, int> numpri;
		int L, U;
		int ans = 0;
		int ansnum = 0;
		cin >> L >> U;
		for (int i = L; i <= U; i++)
		{
			int div = 1;
			numpri.clear();
			int temp = i;
			int sqrti= round(sqrt(i));
			for (int j = 0; j < pri.size() && pri[j] <= sqrti;)
			{
				if (temp%pri[j] == 0)
				{
					numpri[pri[j]]++;
					temp /= pri[j];
				}
				else
				{
					j++;
				}
			}
			if (temp > 1)
			{
				numpri[temp]++;
			}
			for (map<int, int>::iterator it = numpri.begin(); it != numpri.end(); it++)
			{
				div *= it->second + 1;
			}
			if (div > ans)
			{
				ansnum = i;
				ans = div;
			}
		}
		cout << "Between " << L << " and " << U << ", " << ansnum << " has a maximum of " << ans << " divisors." << endl;
	}
}