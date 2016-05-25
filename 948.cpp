#include<iostream>
using namespace std;
int fib[38];
int main()
{
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < 38; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int n, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		cout << x << " = ";
		int i = 0;
		for (; i < 38 && fib[i] <= x; i++);
		i--;
		for (; i >= 0; i--)
		{
			if (x >= fib[i])
			{
				cout << 1;
				x -= fib[i];
			}
			else
			{
				cout << 0;
			}
		}
		cout << " (fib)" << endl;
	}
}