#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int>input;
	vector<int>check;
	int n,x,sum;
	cin >> n;
	while (n--)
	{
		cin >> x;
		sum = 0;
		input.resize(x);
		for (int i = 0; i < x; i++)
		{
			cin >> input[i];
			sum += input[i];
		}
		sort(input.begin(), input.end());
		check.clear();
		check.resize(sum/2+1, -1);
		check[0] = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j <check.size(); j++)
			{
				if (check[j] != -1&& check[j] != i+1)
				{
					if (input[i] + j<check.size()&& check[input[i] + j]==-1)
					{
						check[input[i] + j] = i + 1;
					}
				}
			}
		}
		for (int i = sum / 2; i >= 0; i--)
		{
			if (check[i] != -1)
			{
				cout << sum-i*2 << endl;
				break;
			}
		}
	}
}