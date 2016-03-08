#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int n;
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		while (1)
		{
			while (!s.empty()) s.pop();
			int last = 1, input;
			for (int i = 0; i < n; i++)
			{
				cin >> input;
				if (input == 0)
				{
					goto end;
				}
				while (last<=n)
				{
					if (!s.empty() && s.top() == input)
					{
						s.pop();
						break;
					}
					s.push(last);
					last++;
					
				}
				if (!s.empty() && s.top() == input)
				{
					s.pop();
				}
			}
			if (s.empty())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	end:;
		cout << endl;
	}
}