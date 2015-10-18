#include<iostream>
using namespace std;
int main()
{
	int p, e, i, d;

	for (int c = 1;; c++)
	{
		cin >> p >> e >> i >> d;
		if (p==-1&&e==-1&&i==-1&&d==-1) return 0;
		p %= 23;
		e %= 28;
		i %= 33;
		int ans = (p * 5544 + e * 14421 + i * 1288 - d + 21252) % 21252;
		if (ans == 0) ans = 21252;
		cout << "Case " << c << ": the next triple peak occurs in " << ans << " days." << endl ;

	}
}

/*
21252

6*924=5544
19*759=14421
2*644

*/