#include<iostream>
#include<vector>
using namespace std;
bool alphamap[26][26];
vector<char> point;
int find_group(int id)
{
	if (alphamap[id][id])
	{
		alphamap[id][id] = false;
	}
	else
	{
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < 26; i++)
	{
		if (alphamap[id][i])
		{
			alphamap[id][i] = alphamap[i][id] = false;
			ans += find_group(i);
		}
	}
	return ans;
}
int main()
{
	int n,tree,corn;
	cin >> n;
	char trash, a, b;
	while (n--)
	{
		point.clear();
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				alphamap[i][j] = false;
			}
		}
		tree = corn = 0;
		while (1)
		{
			cin >> trash;
			if (trash == '*')
			{
				cin.ignore(100,'\n');
				break;
			}
			cin >> a >> trash >> b >> trash;
			alphamap[a - 'A'][b - 'A'] = alphamap[b - 'A'][a - 'A']  = true;
		}
		do
		{
			cin >> a;
			alphamap[a - 'A'][a - 'A'] = true;
			point.push_back(a);
		} while (cin.get() == ',');
		for (size_t i = 0; i < point.size(); i++)
		{
			switch (find_group(point[i]-'A'))
			{
			case 0:
				break;
			case 1:
				corn++;
				break;
			default:
				tree++;
			}
		}
		cout << "There are " << tree << " tree(s) and " << corn << " acorn(s)." << endl;
	}
}