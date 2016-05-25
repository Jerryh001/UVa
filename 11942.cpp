#include<iostream>
#include<string>
#include<sstream>
#include<limits>
using namespace std;
int main()
{
	cout << "Lumberjacks:" << endl;
	string in;
	stringstream temp;
	int n,x1,x2;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');//cin.get();
	while (n--)
	{
		int big = 1, small = 1;
		getline(cin, in);
		temp.clear();
		temp << in << endl;
		temp >> x1;
		while (1)
		{
			temp >> x2;
			if (temp.eof()) break;
			if (x1 < x2) big = 0;
			if (x1 > x2)small = 0;
			x1 = x2;
		}
		if (big + small == 0)
		{
			cout << "Unordered" << endl;
		}
		else
		{
			cout << "Ordered" << endl;
		}
	}
}