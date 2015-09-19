#include<iostream>
//#include<fstream>
#include<cmath>
using namespace std;
class Point
{
public:
	int x, y;
	friend istream& operator>>(istream& in, Point& p)
	{
		return in >> p.x >> p.y;
	}
};
bool istouch(const Point& a1, const Point& a2, const Point& l1, const Point& l2)
{
	if (a1.x == a2.x)//a直
	{
		if (l1.x == l2.x)//l直
		{
			return false;//不處理平行
		}
		else//l橫
		{
			return (l1.y - a1.y)*(l2.y - a2.y) <= 0 && (a1.x - l1.x)*(a2.x - l2.x) <= 0;
		}
	}
	else if (a1.y == a2.y)//a橫
	{
		if (l1.y == l2.y)//l橫
		{
			return false;//不處理平行
		}
		else//l直
		{
			return (l1.y - a1.y)*(l2.y - a2.y) <= 0 && (a1.x - l1.x)*(a2.x - l2.x) <= 0;
		}
	}
	else
	{
		double delta = double(a1.y - a2.y) / (a1.x - a2.x);
		if (l1.x == l2.x)//l直
		{
			double y = delta*(l1.x - a2.x) + a2.y;
			return (y - l1.y)*(y - l2.y) <= 0 && (y - a1.y)*(y - a2.y) <= 0;
		}
		else//l橫
		{
			double x = (l1.y - a2.y) / delta + a2.x;
			return (x - l1.x)*(x - l2.x) <= 0 && (x - a1.x)*(x - a2.x) <= 0;
		}
	}
}//(y-a2.y)/(x-a2.x)== delta;
bool isinside(const Point& a, const Point& s1, const Point& s2)
{
	return (a.x - s1.x)*(a.x - s2.x) <= 0 && (a.y - s1.y)*(a.y - s2.y) <= 0;
}
int main()
{
	//ofstream cout("out.txt");
	int n;
	cin >> n;
	Point pa, pb, rect[2];
	int order[4][2] = { 0,0,0,1,1,1,1,0 };
	while (n--)
	{
		cin >> pa >> pb >> rect[0] >> rect[1];
		if (isinside(pa, rect[0], rect[1]) || isinside(pb, rect[0], rect[1]))
		{
			cout << "T" << endl;
			goto end;
		}
		for (int i = 0; i < 4; i++)
		{
			if (istouch(pa, pb, Point{ rect[order[i][0]].x,rect[order[i][1]].y }, Point{ rect[order[(i + 1) % 2][0]].x,rect[order[(i + 1) % 2][1]].y }))
			{
				cout << "T" << endl;
				goto end;
			}
		}
		// (00)(01)(11)(10)
		cout << "F" << endl;
	end:;
	}
}