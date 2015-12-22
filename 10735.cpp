#include<iostream>
#include<cmath>
#include<list>
using namespace std;
int mapd[101][101];
int mapud[101][101];
int indeg[101];
int outdeg[101];
int uddeg[101];
int n, vet, edge, a, b;
char type;
list<int> ans;
void Balance()
{
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 1; i <= vet; i++)
		{
			if (indeg[i] - outdeg[i] > 0)
			{
				for (int j = 1; j <= vet&& (indeg[i] - outdeg[i] > 0); j++)
				{
					while (mapud[j][i]>0 && outdeg[j] - indeg[j] > 0&& (indeg[i] - outdeg[i] > 0))
					{
						change = true;
						mapud[j][i]--;
						mapud[i][j]++;
						indeg[i]--;
						outdeg[i]++;
						indeg[j]++;
						outdeg[j]--;
					}

				}
				for (int j = 1; j <= vet && (indeg[i] - outdeg[i] > 0); j++)
				{
					while (mapud[j][i]>0 && (indeg[i] - outdeg[i] > 0))
					{
						change = true;
						mapud[j][i]--;
						mapud[i][j]++;
						indeg[i]--;
						outdeg[i]++;
						indeg[j]++;
						outdeg[j]--;
					}

				}
			}else if (outdeg[i]-indeg[i] > 0)
			{
				for (int j = 1; j <= vet && (outdeg[i]-indeg[i] > 0); j++)
				{
					while (mapud[i][j]>0 && indeg[j] - outdeg[j] > 0 && (outdeg[i] - indeg[i] > 0))
					{
						change = true;
						mapud[i][j]--;
						mapud[j][i]++;
						indeg[i]++;
						outdeg[i]--;
						indeg[j]--;
						outdeg[j]++;
					}
				}
				for (int j = 1; j <= vet && (outdeg[i] - indeg[i] > 0); j++)
				{
					while (mapud[i][j]>0  && (outdeg[i] - indeg[i] > 0))
					{
						change = true;
						mapud[i][j]--;
						mapud[j][i]++;
						indeg[i]++;
						outdeg[i]--;
						indeg[j]--;
						outdeg[j]++;
					}
				}
			}
		}
	}
}
void F(int i)
{
	for (int j = 1; j <= vet; j++)
	{
		while (mapd[i][j])
		{
			mapd[i][j] --;
			F(j);
		}
	}
	ans.push_back(i);
}
int main()
{
	
	cin >> n;
	while (n--)
	{
		cin >> vet >> edge;
		ans.clear();
		for (int i = 1; i <= vet; i++)
		{
			indeg[i] = outdeg[i]=uddeg[i] = 0;
			for (int j = 1; j <= vet; j++)
			{
				mapd[i][j] = mapud[i][j] = 0;
			}
		}
		for (int i = 0; i < edge; i++)
		{
			cin >> a >> b >> type;
			outdeg[a]++;
			indeg[b]++;
			if (type == 'U')
			{
				mapud[a][b]++;
				uddeg[a]++;
				uddeg[b]++;
			}
			else
			{
				mapd[a][b]++;
			}
		}
		for (int i = 1; i <= vet; i++)
		{
			if (abs(indeg[i] - outdeg[i])>uddeg[i]*2|| (indeg[i] + outdeg[i])%2==1)
			{
				goto nope;
			}
		}
		Balance();
		for (int i = 1; i <= vet; i++)
		{
			for (int j = 1; j <= vet; j++)
			{
				mapd[i][j]+= mapud[i][j];
			}
		}
		F(1);
		nope:
		if (ans.size()==edge+1&&ans.front()==1)
		{
			while (ans.size())
			{
				cout << ans.back();
				ans.pop_back();
				if (ans.size())
				{
					cout << ' ';
				}
				else
				{
					cout << endl;
				}
			}
		}
		else
		{
			cout << "No euler circuit exist" << endl;
		}
		if (n)
		{
			cout << endl;
		}
	}
}