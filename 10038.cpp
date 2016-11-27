#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int map[3001];
	int n,num,pre;
	while (cin >> n)
	{
		for (int i = 1; i < n; i++)
		{
			map[i] = 0;
		}
		cin >> pre;
		for (int i = 1; i < n; i++)
		{
			cin >> num;
			int sub = abs(num - pre);
			if (sub <= 3000)
			{
				map[sub]++;
			}
			pre = num;
		}
		bool isjolly = true;
		for (int i = 1; i < n; i++)
		{
			if (map[i] != 1)
			{
				isjolly = false;
				break;
			}
		}
		if (isjolly)
		{
			cout << "Jolly" << endl;
		}
		else
		{
			cout << "Not jolly" << endl;
		}
	}
}