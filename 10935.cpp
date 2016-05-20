#include<iostream>
#include<list>
using namespace std;
int main()
{
	int n;
	list<int> e;
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		e.clear();
		for (int i = 1; i <= n; i++)
		{
			e.push_back(i);
		}
		cout << "Discarded cards:";
		while (e.size() > 1)
		{
			cout << " " << e.front();
			e.pop_front();
			e.push_back(e.front());
			e.pop_front();
			if (e.size() > 1)
			{
				cout << ',';
			}
		}
		cout <<endl<< "Remaining card: " << e.front()<<endl;

	}
}