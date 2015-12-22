//use c++ 11
#include<iostream>
#include<string>
using namespace std;
int map[26][26];
int choose[26][26];
string input;
int leng = 0;
void F(int i)
{
	leng++;
	for (int j = 0; j < 26; j++)
	{
		if (map[i][j] - choose[i][j])
		{
			choose[i][j]++;
			F(j);
		}
	}
}
int main()
{
	int n,x;
	cin >> n;
	while (n--)
	{
		bool possible = false;
		cin >> x;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < x; i++)
		{
			cin >> input;
			map[input.front() - 'a'][input.back() - 'a']++;
		}
		for (int start = 0; start < 26 && !possible; start++)
		{
			for (int i = 0; i < 26; i++)
			{
				for (int j = 0; j < 26; j++)
				{
					choose[i][j] = 0;
				}
			}
			leng = 0;
			F(start);
			if (leng == x + 1)
			{
				possible = true;
			}
		}
		if (possible)
		{
			cout << "Ordering is possible." << endl;
		}
		else
		{
			cout << "The door cannot be opened." << endl;
		}
	}
}