#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << fixed << setprecision(3);
	int h, m;
	while (1)
	{
		cin >> h;
		cin.get();
		cin >> m;
		if (h == 0 && m == 0) return 0;
		h %= 12;
		float ans = h * 30 - m*5.5;
		if (ans < 0)
		{
			ans = -ans;
		}
		if (ans > 180)
		{
			ans = 360-ans;
		}
		cout << ans << endl;
	}
}