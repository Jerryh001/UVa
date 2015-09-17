#include<iostream>
//#include<fstream>
#include<list>
#include<cmath>
using namespace std;
struct Point
{
	double x, y;
};
struct Rect
{
	Point lefttop;
	Point rightbottom;
};
struct Cycle
{
	Point center;
	double r;
};
struct Tri
{
	Point a, b, c;
};
union Graph
{
	Rect R;
	Cycle C;
	Tri T;
};
struct Figure
{
	Graph G;
	char type;
};
double tri_reg(Point a, Point b, Point c)
{
	return abs(a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x);
}
bool onrect(Point p, Rect r)
{
	return (p.x == r.lefttop.x || p.x == r.rightbottom.x) && (p.y - r.lefttop.y)*(p.y - r.rightbottom.y) <= 0
		|| (p.y == r.lefttop.y || p.y == r.rightbottom.y) && (p.x - r.lefttop.x)*(p.x - r.rightbottom.x) <= 0;
}
bool ontri(Point P, Tri T)
{
	double yadeg = atan2(P.y - T.a.y, P.x - T.a.x);
	return fabs(yadeg - atan2(T.b.y - T.a.y, T.b.x - T.a.x)) < 1e-9
		|| fabs(yadeg - atan2(T.c.y - T.a.y, T.c.x - T.a.x)) < 1e-9
		|| fabs(atan2(P.y - T.c.y, P.x - T.c.x) -atan2(T.b.y - T.c.y, T.b.x - T.c.x)) < 1e-9;
}
int main()
{
	//ifstream cin("in.txt");
	list<Figure> F;
	Point test;
	char type;
	while (1)
	{
		cin >> type;
		if (type == '*') break;
		Figure temp;
		temp.type = type;
		switch (temp.type)
		{
		case 'r':
			cin >> temp.G.R.lefttop.x >> temp.G.R.lefttop.y >> temp.G.R.rightbottom.x >> temp.G.R.rightbottom.y;
			break;
		case 'c':
			cin >> temp.G.C.center.x >> temp.G.C.center.y >> temp.G.C.r;
			break;
		case 't':
			cin >> temp.G.T.a.x >> temp.G.T.a.y >> temp.G.T.b.x >> temp.G.T.b.y >> temp.G.T.c.x >> temp.G.T.c.y;
			break;
		}
		F.push_back(temp);
	}
	for (int pointid = 1;;pointid++)
	{
		int notin = 1;
		cin >> test.x >> test.y;
		if (fabs(9999.9 - test.x) < 1e-9 && fabs(9999.9 - test.y) < 1e-9)
			return 0;
		int id = 1;
		for (list<Figure>::iterator i = F.begin(); i != F.end(); i++, id++)
		{
			switch (i->type)
			{
			case 'r':
				if (test.x - i->G.R.lefttop.x > 0 && test.x - i->G.R.rightbottom.x < 0 && test.y - i->G.R.lefttop.y < 0 && test.y - i->G.R.rightbottom.y > 0&&!onrect(test, i->G.R))
				{
					cout << "Point " << pointid << " is contained in figure " << id << endl;
					notin = 0;
				}
				break;
			case 'c':
				if (sqrt(pow(test.x - i->G.C.center.x, 2) + pow(test.y - i->G.C.center.y, 2))<i->G.C.r)
				{
					cout << "Point " << pointid << " is contained in figure " << id << endl;
					notin = 0;
				}
				break;
			case 't':
				if (fabs(tri_reg(test, i->G.T.a, i->G.T.b) + tri_reg(test, i->G.T.c, i->G.T.b) + tri_reg(test, i->G.T.a, i->G.T.c) - tri_reg(i->G.T.a, i->G.T.b, i->G.T.c) )< 1e-9&&!ontri(test,i->G.T))
				{
					cout << "Point " << pointid << " is contained in figure " << id << endl;
					notin = 0;
				}
				break;
			}
		}
		if (notin == 1)
		{
			cout << "Point " << pointid << " is not contained in any figure" << endl;
		}
	}
}