#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
struct kword
{
	int range;
	int count = 0;
	list<string> word;
	list<int> foundtext;
	string* hold=NULL;
};
int main()
{
	string put;
	list<kword> keyword;
	int stringID = 1;
	bool islastword = false;
	while (1)
	{
		cin >> put;
		switch (put[0])
		{
		case 'P':
		{
			kword k;
			cin >> k.range;
			while (cin.get() != '\n')
			{
				cin >> put;
				k.word.push_back(put);
			}
			keyword.push_back(k);
		}
		break;
		case 'T':
		{
			islastword = false;
			while (!islastword)
			{
				cin >> put;
				if (put.back() == '|') islastword=true;
				for (string::iterator i = put.begin(); i != put.end();)
				{
					if (!isalpha(*i))
					{
						i = put.erase(i);
					}
					else
					{
						if (isupper(*i))
						{
							*i = tolower(*i);
						}
						i++;
					}
				}
				if (put.length() == 0) continue;
				for (list<kword>::iterator i = keyword.begin(); i != keyword.end(); i++)
				{
					for (list<string>::iterator j = i->word.begin(); j != i->word.end(); j++)
					{
						if (i->hold != &*j)
						{
							if (*j == put)
							{
								if (i->hold == NULL)
								{
									i->hold = &*j;
									i->count = i->range+1;
								}
								else if (i->count>=0&&i->hold != &*j)
								{
									//found
									if (find(i->foundtext.begin(), i->foundtext.end(), stringID) == i->foundtext.end())
									{
										i->foundtext.push_back(stringID);
										break;
									}
								}
								break;
							}
						}
					}
					if (i->count == 0) i->hold = NULL;
					i->count--;
				}
			}
			for (list<kword>::iterator i = keyword.begin(); i != keyword.end(); i++)
			{
				i->hold = NULL;
			}
			stringID++;
		}
		break;
		case '#':
		{
			int ID = 1;
			for (list<kword>::iterator i = keyword.begin(); i != keyword.end(); i++, ID++)
			{
				cout << ID << ": ";
				for (list<int>::iterator j = i->foundtext.begin(); j != i->foundtext.end(); j++)
				{
					if (j != i->foundtext.begin()) cout << ',';
					cout << *j;
				}
				cout << endl;
			}
			return 0;
		}
		}
		
	}
}