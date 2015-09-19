#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
double pi = M_PI;
int rearth = 6440;
int main()
{
	cout << fixed << setprecision(6);
	while (1)
	{
		int s, a;
		char type;
		cin >> s;
		if (cin.eof()) return 0;
		cin >> a >> type;
		cin.ignore(10, '\n');
		if (type == 'd')
		{
			a *= 60;
		}
		if (a > 10800) a = 21600 - a;
		cout << 2 * pi*(rearth + s)*a / 21600 << " " << sin(a*pi / 21600)*(rearth + s) * 2 << endl;
	}
}