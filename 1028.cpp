#include<iostream>
#include<list>
using namespace std;
int maps[410][410][2];
int* m(const int& i, const int& j)
{
	return maps[i + 205][j + 205];
}
struct ant
{
	int i;
	int j;
	int order;
};
struct ij
{
	int i;
	int j;
};
ant a[101];
list<int> finish;
list<ij> pa;
int main()
{
	int c;
	cin >> c;
	for (int time = 1; time <= c; time++)
	{
		for (int i = -201; i <= 201; i++)
		{
			for (int j = -201; j <= 201; j++)
			{
				m(i, j)[0] = 0;
				m(i, j)[1] = 0;
			}
		}
		finish.clear();
		pa.clear();
		int si = 0, sj = 0;
		int ei, ej;
		int path, ants, delay;
		cin >> path >> ants >> delay;
		int count = 2;
		pa.push_back({ 0,0 });
		//m(0, 0)[0] = 1;
		for (int ct = 0; ct < path; ct++)
		{
			cin >> ei >> ej;
			if (ei > si)
			{
				for (int i = si + 1; i <= ei; i++)
				{
					pa.push_back({ i,sj });
					//m(i, sj)[0] = count;
					count++;
				}
			}
			else if (ei < si)
			{
				for (int i = si - 1; i >= ei; i--)
				{
					pa.push_back({ i,sj });
					//m(i, sj)[0] = count;
					count++;
				}
			}
			else if (ej > sj)
			{
				for (int j = sj + 1; j <= ej; j++)
				{
					pa.push_back({ si,j });
					//m(si, j)[0] = count;
					count++;
				}
			}
			else if (ej < sj)
			{
				for (int j = sj - 1; j >= ej; j--)
				{
					pa.push_back({ si,j });
					//m(si, j)[0] = count;
					count++;
				}
			}
			si = ei;
			sj = ej;
		}
		for (int i = 1; i <= ants; i++)
		{
			a[i] = { -10000,-10000,i };
		}
		int clock = 0;
		for (;; clock++)
		{
			if (clock && !pa.empty())
			{
				ij temp = pa.front();
				pa.pop_front();
				m(temp.i, temp.j)[0] = clock;
			}

			for (int i = 1; i <= ants; i++)
			{
				if (a[i].i == -10000) continue;

				if (m(a[i].i + 1, a[i].j)[0] <= clock&&m(a[i].i + 1, a[i].j)[0] > m(a[i].i, a[i].j)[0])
				{
					if (m(a[i].i + 1, a[i].j)[1] == 0)
					{
						m(a[i].i, a[i].j)[1] = 0;
						a[i].i++;
						m(a[i].i, a[i].j)[1] = a[i].order;
					}
				}
				else if (m(a[i].i - 1, a[i].j)[0] <= clock&&m(a[i].i - 1, a[i].j)[0] > m(a[i].i, a[i].j)[0])
				{
					if (m(a[i].i - 1, a[i].j)[1] == 0)
					{
						m(a[i].i, a[i].j)[1] = 0;
						a[i].i--;
						m(a[i].i, a[i].j)[1] = a[i].order;
					}
				}
				else if (m(a[i].i, a[i].j + 1)[0] <= clock&&m(a[i].i, a[i].j + 1)[0] > m(a[i].i, a[i].j)[0])
				{
					if (m(a[i].i, a[i].j + 1)[1] == 0)
					{
						m(a[i].i, a[i].j)[1] = 0;
						a[i].j++;
						m(a[i].i, a[i].j)[1] = a[i].order;
					}
				}
				else if (m(a[i].i, a[i].j - 1)[0] <= clock&&m(a[i].i, a[i].j - 1)[0] > m(a[i].i, a[i].j)[0])
				{
					if (m(a[i].i, a[i].j - 1)[1] == 0)
					{
						m(a[i].i, a[i].j)[1] = 0;
						a[i].j--;
						m(a[i].i, a[i].j)[1] = a[i].order;
					}
				}
				if (m(a[i].i, a[i].j)[0] == count - 1)
				{
					m(a[i].i, a[i].j)[1] = 0;
					finish.push_back(a[i].order);
					a[i].i = -10000;
				}
			}
			if (clock%delay == 0 && clock / delay <= ants)
			{
				a[clock / delay].i = 0;
				a[clock / delay].j = 0;
				m(0, 0)[1] = a[clock / delay].order;
			}
			if (finish.size() == ants)
			{
				break;
			}
		}
		cout << "Case " << time << ":" << endl
			<< "Carl finished the path at time " << count - 1 << endl
			<< "The ants finished in the following order :" << endl << "0";
		//finish.pop_front();
		for (list<int>::iterator it = finish.begin(); it != finish.end(); it++)
		{
			cout << " " << (*it) - 1;
		}
		cout << endl << "The last ant finished the path at time " << clock << endl;
	}
}