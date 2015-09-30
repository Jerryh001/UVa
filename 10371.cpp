#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<map>
#include<string.h>
using namespace std;
map<string, float> zones = {
	{ "UTC",0 },
	{ "GMT", 0 },
	{ "BST", 1 },
	{ "IST", 1 },
	{ "WET", 0 },
	{ "WEST", 1 },
	{ "CET", 1 },
	{ "CEST", 2 },
	{ "EET", 2 },
	{ "EEST", 3 },
	{ "MSK", 3 },
	{ "MSD", 4 },
	{ "AST", -4 },
	{ "ADT", -3 },
	{ "NST", -3.5 },
	{ "NDT", -2.5 },
	{ "EST", -5 },
	{ "EDT", -4 },
	{ "CST", -6 },
	{ "CDT", -5 },
	{ "MST", -7 },
	{ "MDT", -6 },
	{ "PST", -8 },
	{ "PDT", -7 },
	{ "HST", -10 },
	{ "AKST", -9 },
	{ "AKDT", -8 },
	{ "AEST", 10 },
	{ "AEDT", 11 },
	{ "ACST", 9.5 },
	{ "ACDT", 10.5 },
	{ "AWST", 8 } };
void gettime(int& h, int& m, string& type)
{
	string time;
	cin >> time;
	if (time == "noon")
	{
		h = 12;
		m = 0;
		type = "a.m.";
	}
	else if (time == "midnight")
	{
		h = 0;
		m = 0;
		type = "a.m.";
	}
	else
	{
		h = 0;
		int i = 0;
		for (; time[i] != ':'; i++)
		{
			h *= 10;
			h += time[i] - '0';
		}
		m = (time[i + 1] - '0') * 10 + (time[i + 2] - '0');
		cin >> type;
		if (h == 12)
		{
			h = 0;
		}
		if (type[0] == 'p')
		{
			h += 12;
			type[0] = 'a';
		}
	}
}
//#define cout out
//ofstream out("out.txt");
void outputtime(int& h, int& m, string& type, const float& delta)
{
	
	if (fmod(abs(delta), 1) > 0.4&&fmod(abs(delta), 1)<0.6)
	{
		m += 30;
		if (m >= 60)
		{
			m %= 60;
			h++;
		}
		h += floor(delta);
	}
	else
	{
		h += round(delta);
	}
	
	if (h < 0) h += 24;
	h %= 24;
	if (h > 12||h==12&&m!=0)
	{
		h -= 12;
		type[0] = 'p';
	}
	if (h == 0 && m == 0)
	{
		cout << "midnight" << endl;
	}
	else if (h == 12 && m == 0)
	{
		cout << "noon" << endl;
	}
	else
	{
		if (h == 0) h = 12;
		cout << h << ":";
		if (m < 10)cout << '0';
		cout << m << " " << type << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	string type, zonea, zoneb;
	int h, m;
	while (n--)
	{
		gettime(h, m, type);
		cin >> zonea >> zoneb;
		float delta = zones[zoneb] - zones[zonea];
		outputtime(h, m, type, delta);
	}
}