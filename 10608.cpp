#include<iostream>
using namespace std;
bool relate[30000][30000];
int group[30000];
int n, people, tempa, tempb;
int find_group(int id,int p)
{
	int ans = 1;
	if (group[p] == 0)
	{
		group[p] = id;
		for (int i = 0; i < people; i++)
		{
			if (relate[p][i])
			{
				ans+=find_group(id, i);
			}
			
		}
		return ans;
	}
	return 0;
}
int main()
{
	cin >> n;
	int pair,ans,tempans;
	while (n--)
	{
		ans = 0;
		tempans = 0;
		cin >> people >> pair;
		for (int i = 0; i < people; i++)
		{
			group[i] = 0;
			for (int j = 0; j < people; j++)
			{
				relate[i][j] = false;
			}
		}
		for (int i = 0; i < pair; i++)
		{
			cin >> tempa >> tempb;
			tempa--; tempb--;
			relate[tempa][tempb] = relate[tempb][tempa] = true;
		}
		for (int id = 1,p=0;p<people;p++)
		{
			tempans=find_group(id, p);
			if (tempans > ans)
			{
				ans = tempans;
			}
			if (tempans != 0)
			{
				id++;
			}
		}
		cout << ans << endl;
	}
}