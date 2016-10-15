#include<iostream>
#include<algorithm>
using namespace std;
int threen(long long int in)
{
	int ans = 1;
	while (in > 1)
	{
		if (in % 2 == 0)
		{
			in /= 2;
		}
		else
		{
			in = 3 * in + 1;
		}
		ans++;
	}
	return ans;
}
int main()
{
	int L, U;
	while (cin >> L >> U)
	{
		cout << L << " " << U << " ";
		if (L > U) swap(L, U);
		int ans = 0;
		int temp;
		for (int i = L; i <= U; i++)
		{
			temp = threen(i);
			if (temp > ans)
			{
				ans = temp;
			}
		}
		cout << ans << endl;
	}
}