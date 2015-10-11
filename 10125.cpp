#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> num;
vector<vector<int>> aplusb;//a,b,a+b
vector<vector<int>> dminusc;//d,c,d-c
bool sortab(const vector<int>& a, const vector<int>& b)
{
	if (a[2] == b[2])
	{
		return a[0] > b[0];
	}
	else
	{
		return a[2] > b[2];
	}
}
bool sortcd(const vector<int>& a, const vector<int>& b)
{
	if (a[0] == b[0])
	{
		return a[2] > b[2];
	}
	else
	{
		return a[0] > b[0];
	}
}
int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;
		num.clear();
		num.resize(n);
		aplusb.clear();
		aplusb.reserve(n*(n - 1));
		dminusc.clear();
		dminusc.reserve(n*(n - 1));
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		sort(num.begin(), num.end());
		for (int a = 0; a < n - 1; a++)
		{
			//c==a
			for (int b = a + 1; b < n; b++)
			{
				//d==b
				aplusb.push_back({ a, b, num[a] + num[b] });
				dminusc.push_back({ b,a,num[b] - num[a] });
			}
		}
		sort(aplusb.begin(), aplusb.end(), sortab);
		sort(dminusc.begin(), dminusc.end(), sortcd);
		for (vector<vector<int>>::iterator i = dminusc.begin(); i != dminusc.end(); i++)
		{
			int LB = 0;
			int UB = aplusb.size() - 1;
			while (UB >= LB)
			{
				int mid = (LB + UB) / 2;
				if (i->at(2) > aplusb[mid][2])
				{
					UB = mid - 1;
				}
				else if (i->at(2) < aplusb[mid][2])
				{
					LB = mid + 1;
				}
				else
				{
					LB++;
					if (i->at(0) != aplusb[mid][0] && i->at(1) != aplusb[mid][1] && i->at(0) != aplusb[mid][1] && i->at(1) != aplusb[mid][0])
					{
						cout << num[i->at(0)] << endl;
						goto end;
					}
				}
			}
		}
		cout << "no solution" << endl;
	end:;
	}
}