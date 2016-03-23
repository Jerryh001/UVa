#include<iostream>
using namespace std;
int T, N,up,down;
int block[50];
int main()
{
	
	cin >> T;
	for (int case_count = 1; case_count <= T; case_count++)
	{
		up = 0;
		down = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> block[i];
		}
		for (int i = 1; i < N; i++)
		{
			if (block[i - 1] < block[i])
			{
				up++;
			}
			else if (block[i - 1] > block[i])
			{
				down++;
			}
		}
		cout << "Case " << case_count << ": " << up << " " << down << endl;
	}
}