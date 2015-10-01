#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int p, q, r, s, t, u;
double F(double x)
{
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main()
{
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		//cout << F(0.2880) << endl;
		double UP = 1;
		double LOW = 0;
		double mid = 0.5;
		if (F(1)*F(0) > 0)
		{
			cout << "No solution" << endl;
		}
		else if (fabs(F(1)) < 1e-9)
		{
			cout << "1.0000" << endl;
		}
		else if (fabs(F(0)) < 1e-9)
		{
			cout << "0.0000" << endl;
		}
		else
		{
			while (UP - LOW > 1e-9)
			{
				if (F(mid)*F(UP) < 0)
				{
					LOW = mid;
				}
				else
				{
					UP = mid;
				}
				mid = (UP + LOW) / 2;
			}
			cout << fixed << setprecision(4) << mid << endl;
		}
	}
}