#include<iostream>
//#include<fstream>
#include<list>
#include<vector>
using namespace std;
class Bignum
{
	list<int> num;
public:
	Bignum(int i)
	{
		num.push_back(i);
	}
	Bignum()
	{
		
	}
	friend void add(Bignum& ans, const Bignum& a, const Bignum& b)
	{
		ans = a;
		int carry = 0;
		list<int>::iterator ia = ans.num.begin();
		list<int>::const_iterator ib = b.num.begin();
		for (;; ia++, ib++)
		{
			if (ib == b.num.end())
			{
				if (carry)
				{
					if (ia == ans.num.end())
					{
						ans.num.push_back(carry);
					}
					else
					{
						ans.num.back() += carry;
					}
				}
				return;
			}
			if (ia == ans.num.end())
			{
				ans.num.push_back(0);
				ia = --ans.num.end();
			}
			*ia += *ib+carry;
			carry = *ia / 10000;
			*ia %= 10000;
		}
	}
	friend ostream& operator<<(ostream& out, Bignum b)
	{
		out << b.num.back();
		for (list<int>::const_reverse_iterator i = ++b.num.rbegin(); i != b.num.rend(); i++)
		{
			if (*i < 1000)
			{
				out << 0;
			}
			if (*i < 100)
			{
				out << 0;
			}
			if (*i < 10)
			{
				out << 0;
			}
			out << *i;
		}
		return out;
	}
};

int main()
{
	//ofstream cout("out.txt");
	vector<Bignum> B;
	B.resize(5001);
	B[0] = 0;
	B[1] = 1;
	for (int i = 2; i < 5001; i++)
	{
		add(B[i], B[i - 1], B[i - 2]);
		//cout << B[i] << endl;
	}
	int a;
	while (1)
	{
		cin >> a;
		if (cin.eof()) return 0;
		cout << "The Fibonacci number for " << a << " is " << B[a] << endl;
	}
	//cout << B[5000] << endl;
}


