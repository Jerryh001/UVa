#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct route
{
	string type;
	vector<int> boattime;
	int time;
};
vector<route> roads;
double search(const double& speed)
{
	double time = 0;
	for (int i = 0; i < roads.size(); i++)
	{
		if (roads[i].type == "road")
		{
			time += 3600.0*roads[i].time / speed;
		}
		else
		{
			time = ceil(time);
			int minute = int(ceil(time / 60)) % 60;
			int found = 0;
			for (int j = 0; j < roads[i].boattime.size(); j++)
			{
				if (minute <= roads[i].boattime[j])
				{
					found = 1;
					time += (roads[i].boattime[j] - minute) * 60;
					break;
				}
			}
			if (found == 0)
			{
				time += (roads[i].boattime[0] - minute + 60) * 60;
			}
			time += (60 - int(time) % 60) % 60;
			time += roads[i].time * 60;
		}
	}
	return time;
}
int main()
{
	int n;
	string trash, type, last;

	for (int c = 1;; c++)
	{
		cin >> n;
		if (!n) return 0;
		double mintime = 0;
		roads.clear();
		for (int i = 0; i < n; i++)
		{
			route r;
			cin >> trash >> trash >> r.type;
			if (r.type == "road")
			{
				cin >> r.time;
			}
			else
			{
				int x;
				cin >> r.time >> x;
				for (int j = 0; j < x; j++)
				{
					int t;
					cin >> t;
					r.boattime.push_back(t);
				}
			}
			roads.push_back(r);
		}
		double L = 0, U = 80;
		mintime = search(80);
		while (U - L > 1e-9)
		{
			double mid = (U + L) / 2;
			double newtime = search(mid);
			if (newtime <= mintime)
			{
				mintime = newtime;
				U = mid;
			}
			else
			{
				L = mid;
			}
		}
		cout << "Test Case " << c << ": ";
		cout << setfill('0') << setw(2) << int(mintime) / 3600;
		cout << ":";
		cout << setfill('0') << setw(2) << (int(mintime) / 60) % 60;
		cout << ":";
		cout << setfill('0') << setw(2) << int(mintime) % 60;
		cout << " " << fixed << setprecision(2) << L << endl;
		cout << scientific;
		cout << endl;
	}
}