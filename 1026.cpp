#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
bool allzero(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f)
{
	return fabs(a) < 1e-9&&fabs(b) < 1e-9&&fabs(c) < 1e-9&&fabs(d) < 1e-9&&fabs(e) < 1e-9&&fabs(f) < 1e-9;
}
int main()
{
	double a1, b1, t1, a2, b2, t2, t;
	for (int count = 1;;count++)
	{
		cin >> a1 >> b1 >> t1 >> a2 >> b2 >> t;
		if (allzero(a1, b1, t1, a2, b2, t)) return 0;
		t2 = sqrt(pow(a2, 3) / pow(a1, 3)*pow(t1, 2));
		t = fmod(t, t2);
		bool yisnega = false;
		if (t * 2 > t2)
		{
			//y<0;
			yisnega = true;
			t = t2 - t;
		}
		double UB = a2, LB = -a2;
		double ansarea = M_PI*a2*b2*t / t2;//blue
		double epsilon = sqrt(1 - b2*b2 / (a2*a2));
		double mid, y;
		while (UB - LB > 1e-9)
		{
			mid = (UB + LB) / 2;
			double sita = acos(mid / a2);
			y = sin(sita)*b2;
			double area = a2*a2*sita / 2 * (b2 / a2) - epsilon*a2*y / 2;
			//blue=green*b/a-red because green=red+blue
			if (fabs(area - ansarea) < 1e-9)
			{
				break;
			}
			else if (area > ansarea)
			{
				LB = mid;
			}
			else
			{
				UB = mid;
			}
		}
		if (yisnega) y = -y;
		cout << fixed << setprecision(3) << "Solar System "<<count<<": " << mid << " " << y << endl;
	}
}
