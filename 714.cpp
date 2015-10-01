#include<iostream>
#include<fstream>
#include<vector>
#include<list>
using namespace std;
vector<long int> items;
list< pair<long int, int> > endflag;//總和,結束位置 可能的答案
list< pair<long int, int> > ans;//最後答案
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int job, part;
		long int UB=0, LB=0;
		
		cin >> job >> part;
		items.resize(job);
		for (int i = 0; i < job; i++)
		{
			cin >> items[i];
			UB += items[i];
			if (items[i] > LB)
			{
				LB = items[i];
			}
		}
		long int mid;
		while (UB!=LB)
		{
			endflag.clear();
			bool fail = false;
			mid = (UB + LB) / 2;
			pair<long int, int> temp(0,job-1);
			for (int i = job - 1; i >= 0; i--)
			{
				if (temp.first + items[i] <= mid)
				{
					temp.first += items[i];
					if (part - endflag.size() -1== i)
					{
						endflag.push_front(temp);
						temp.second = i-1;
						temp.first = 0;
					}
				}
				else
				{
					endflag.push_front(temp);
					temp.second = i;
					temp.first = items[i];
				}
				int leftpart = part - endflag.size() - (temp.first != 0);
				if (leftpart < 0)
				{
					fail = true;
					break;
				}
			}
			if (fail)
			{
				LB = mid+1;
			}
			else
			{
				ans.clear();
				UB = mid;
				ans = endflag;
			}
		}
		
		for (int i = 0; i < job; i++)
		{
			if (i != 0) cout << " ";
			cout << items[i];
			if (i == ans.front().second&&i!=job-1)
			{
				cout << " /";
				ans.pop_front();
			}
		}
		cout << endl;
	}
}