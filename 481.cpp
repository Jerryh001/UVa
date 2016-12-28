#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	//ofstream cout("out.txt");
	vector<int> ori, sorted,pos;
	int n;
	while (cin >> n)
	{
		ori.push_back(n);
	}
	for (vector<int>::iterator it = ori.begin(); it != ori.end(); it++)
	{
		if (sorted.empty()||sorted.back()<*it)
		{
			sorted.push_back(*it);
			pos.push_back(sorted.size());
		}
		else
		{
			for (int i=0; i < sorted.size(); i++)
			{
				if (*it <= sorted[i])
				{
					sorted[i] = *it;
					pos.push_back(i + 1);
					break;
				}
			}
		}
	}
	int length = sorted.size();
	sorted.clear();
	cout << length << endl << '-' << endl;
	for (int i = ori.size() - 1; i >= 0; i--)
	{
		if (pos[i] == length)
		{
			sorted.push_back(ori[i]);
			length--;
		}
	}
	reverse(sorted.begin(), sorted.end());
	for (vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++)
	{
		cout << *it << endl;
	}
}