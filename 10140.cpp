#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
vector<int> pri;
bool primap[1000001];
bool ispri(const int& i)
{
	int sqrti = round(sqrt(i));
	for (int j = 0; j < pri.size() && pri[j] <= sqrti; j++)
	{
		if (i%pri[j] == 0)
		{
			return false;
		}
	}
	return true;
}
bool ispri2(const int& i)
{
	return !primap[i];
}
struct pridis
{
	int a;
	int b;
	int dis;
};
int main()
{
	pri.push_back(2);
	for (int i = 3; i < 46341; i++)
	{
		if (ispri(i))
		{
			pri.push_back(i);
		}
	}
	int L, U;
	while (1)
	{
		
		int lastpri = -1;
		cin >> L >> U;
		if (cin.eof()) return 0;
		memset(primap, false, U-L+1);
		pridis mindis = { 0, U, U };
		pridis maxdis = { 0,0,0 };
		for (int i = 0; i < pri.size()&&pri[i]<=U; i++)
		{
			int offset = -L % pri[i];
			if (offset < 0)
			{
				offset += pri[i];
			}
			if (L + offset == pri[i])
			{
				offset += pri[i];
			}
			while (offset <= U-L+1)
			{
				primap[offset] = true;
				offset += pri[i];
			}
		}
		if (L == 1)
		{
			primap[0] = true;
		}
		for (int i = 0; i <U-L+1; i++)
		{
			if (ispri2(i))
			{
				if (lastpri != -1)
				{
					if (i - lastpri > maxdis.dis)
					{
						maxdis = { lastpri,i,i - lastpri };
					}
					if (i - lastpri < mindis.dis)
					{
						mindis = { lastpri,i,i - lastpri };
					}
				}
				lastpri = i;
			}
		}
		if (maxdis.dis == 0)
		{
			cout << "There are no adjacent primes." << endl;
		}
		else
		{
			cout << mindis.a+L<<","<<mindis.b + L <<" are closest, "<< maxdis.a + L <<","<<maxdis.b + L <<" are most distant." << endl;
		}
	}
}