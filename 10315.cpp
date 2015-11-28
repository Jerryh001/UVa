#include<iostream>
#include<algorithm>
using namespace std;
class card
{
public:
	int number;
	int type;
	friend istream& operator>>(istream& in, card& c)
	{
		char num, t;
		in >> num >> t;
		switch (num)
		{
		case 'A':
			c.number = 14;
			break;
		case 'K':
			c.number = 13;
			break;
		case 'Q':
			c.number = 12;
			break;
		case 'J':
			c.number = 11;
			break;
		case 'T':
			c.number = 10;
			break;
		default:
			c.number = num - '0';
			break;
		}
		switch (t)
		{
		case 'S':
			c.type = 3;
			break;
		case 'H':
			c.type = 2;
			break;
		case 'D':
			c.type = 1;
			break;
		case 'C':
			c.type = 0;
			break;
		}
		return in;
	}
};
bool sort_number(const card& a, const card& b)
{
	if (a.number == b.number) return a.type < b.type;
	return a.number < b.number;
}
//high card=1,pair=2,two pair=3,three of kind=4,straight=5,flush=6,fullhouse=7,four of kind=8,straight=9
int cardrank(card cards[5])
{
	bool issamesuit = true;
	int maxsamenum = 0;
	bool isstraight = true;
	for (int i = 0; i < 4; i++)
	{
		if (cards[i].type != cards[i + 1].type)
		{
			issamesuit = false;
			break;
		}
	}
	sort(cards, cards + 5, sort_number);
	int temp = 1;
	for (int i = 0; i < 4; i++)
	{
		if (cards[i].number != cards[i + 1].number - 1)
		{
			isstraight = false;
		}
		if (cards[i].number == cards[i + 1].number)
		{
			temp++;
		}
		else
		{
			if (temp > maxsamenum)
			{
				maxsamenum = temp;
			}
			temp = 1;
		}
	}
	if (temp > maxsamenum)
	{
		maxsamenum = temp;
	}
	if (issamesuit&&isstraight)
	{
		return 9;
	}
	if (maxsamenum == 4)
	{
		if (cards[0].number == cards[3].number)
		{
			swap(cards[0], cards[4]);
		}
		return 8;
	}
	if (maxsamenum == 3)
	{
		temp = 1;
		for (int i = 0; i < 4; i++)
		{
			if (cards[i].number == cards[i + 1].number)
			{
				temp++;
			}
			else
			{
				if (temp == 2)
				{
					if (cards[0].number == cards[2].number)
					{
						swap(cards[0], cards[4]);
						swap(cards[1], cards[3]);
					}
					return 7;
				}
				temp = 1;
			}
		}
		if (temp == 2)
		{
			if (cards[0].number == cards[2].number)
			{
				swap(cards[0], cards[4]);
				swap(cards[1], cards[3]);
			}
			return 7;
		}
	}
	if (issamesuit)
	{
		return 6;
	}
	if (isstraight)
	{
		return 5;
	}
	if (maxsamenum == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			if (cards[i].number == cards[i + 1].number)
			{
				if (i != 2)
				{
					swap(cards[2], cards[i]);
					swap(cards[3], cards[i + 1]);
					swap(cards[4], cards[i + 2]);
				}
				break;
			}
		}
		return 4;
	}
	if (maxsamenum == 2)
	{
		int pairs = 0;
		temp = 1;
		for (int i = 0; i < 4; i++)
		{
			if (cards[i].number == cards[i + 1].number)
			{
				temp++;
			}
			else
			{
				if (temp == 2)
				{
					pairs++;
				}
				temp = 1;
			}
		}
		if (temp == 2)
		{
			pairs++;
		}
		if (pairs == 2)
		{
			if (cards[3].number != cards[4].number)
			{
				for (int i = 4; i > 0; i--)
				{
					swap(cards[i], cards[i - 1]);
				}
			}
			else if (cards[1].number != cards[2].number)
			{
				swap(cards[1], cards[2]);
				swap(cards[0], cards[1]);
			}
			return 3;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (cards[i].number == cards[i + 1].number)
				{
					if (i != 3)
					{
						swap(cards[3], cards[i]);
						swap(cards[4], cards[i + 1]);
						sort(cards, cards + 3, sort_number);
					}
					break;
				}
			}
			return 2;
		}
	}
	return 1;
}
int main()
{
	card white[5], black[5];
	while (1)
	{
		cin >> black[0];
		if (cin.eof()) return 0;
		for (int i = 1; i < 5; i++)
		{
			cin >> black[i];
		}
		for (int i = 0; i < 5; i++)
		{
			cin >> white[i];
		}
		int wrank = cardrank(white);
		int brank = cardrank(black);
		if (wrank > brank)
		{
			cout << "White wins." << endl;
		}
		else if (brank > wrank)
		{
			cout << "Black wins." << endl;
		}
		else
		{
			for (int i = 4; i >= 0; i--)
			{
				if (white[i].number > black[i].number)
				{
					wrank = 100;
					break;
				}
				else if (white[i].number < black[i].number)
				{
					brank = 100;
					break;
				}
			}
			if (wrank > brank)
			{
				cout << "White wins." << endl;
			}
			else if (brank > wrank)
			{
				cout << "Black wins." << endl;
			}
			else
			{
				cout << "Tie." << endl;
			}
		}
	}
}