#include<iostream>
//#include<fstream>
#include<list>
#include<string>
#include<cstdlib>
using namespace std;
class Bignum
{
public:
	list<int> num;
	Bignum()
	{
		num.push_back(0);
	}
	Bignum(const Bignum& b)
	{
		num = b.num;
		if (num.size() == 0)
		{
			num.push_back(0);
		}
	}
	Bignum(int i)
	{
		while (i > 0)
		{
			num.push_back(i % 10000);
			i /= 10000;
		}
	}
	Bignum(const string& s)
	{
		init(s);
	}
	Bignum operator=(const Bignum& b)
	{
		num = b.num;
		while (num.size() > 1 && num.back() == 0)
		{
			num.pop_back();
		}
		return *this;
	}
	friend Bignum Bigsqrt(Bignum num)
	{
		Bignum r, a(10);
		int b = 0;
		int round;
		if (num.num.back() > 99)
		{
			r = num.num.back() / 100;
			round = 0;
		}
		else
		{
			r = num.num.back();
			num.num.pop_back();
			round = 1;
		}
		while (a*a > r)
		{
			a = a - 1;
		}
		r = r - (a*a);
		while (num.num.size())
		{
			r = r * 100;
			if (round)
			{
				r = r + num.num.back() / 100;
				round = 0;
			}
			else
			{
				r = r + num.num.back() % 100;
				num.num.pop_back();
				round = 1;
			}
			b = 9;
			while ((20 * a + b)*b > r)
			{
				b--;
			}
			r = r - (20 * a + b)*b;
			a = a * 10 + b;

		}
		return a;
	}
	friend Bignum operator*(const Bignum& a, const Bignum& b)
	{
		int carry = 0;
		Bignum ans(0);
		ans.num.resize((a.num.size())*(b.num.size())+1);
		list<int>::const_iterator i = a.num.begin();
		list<int>::iterator ians = ans.num.begin();
		for (; i != a.num.end() && ians != ans.num.end(); i++, ians++)
		{
			list<int>::const_iterator j = b.num.begin();
			list<int>::iterator jans = ians;
			for (; j != b.num.end(); j++, jans++)
			{
				*jans += carry + (*i)*(*j);
				if (carry = *jans / 10000)
				{
					*jans %= 10000;
				}
			}
			while (carry)
			{
				*jans += carry;
				if (carry = *jans / 10000)
				{
					*jans %= 10000;
					jans++;
				}
			}
		}
		while (ans.num.size() > 1 && ans.num.back() == 0)
		{
			ans.num.pop_back();
		}
		return ans;
	}
	void init(string s)
	{
		num.clear();
		int reminder = s.length() % 4;
		if (reminder == 0)
		{
			reminder = 4;
		}
		num.push_front(atoi(s.substr(0, reminder).c_str()));
		s = s.substr(reminder);
		while (s.length() > 0)
		{
			num.push_front(atoi(s.substr(0, 4).c_str()));
			s = s.substr(4);
		}
	}
	friend Bignum operator+(Bignum a, const Bignum& b)
	{
		int carry = 0;
		list<int>::iterator ia = a.num.begin();
		list<int>::const_iterator ib = b.num.begin();
		for (;; ia++, ib++)
		{
			if (ib == b.num.end())
			{
				if (carry)
				{
					if (ia == a.num.end())
					{
						a.num.push_back(carry);
					}
					else
					{
						a.num.back() += carry;
					}
				}
				while (a.num.size() > 1 && a.num.back() == 0)
				{
					a.num.pop_back();
				}
				return a;
			}
			if (ia == a.num.end())
			{
				a.num.push_back(0);
			}
			*ia += (*ib) + carry;
			if (carry = *ia / 10000)
			{
				*ia %= 10000;
			}
		}
	}
	friend Bignum operator-(Bignum a, const Bignum& b)//a must>b
	{
		int borrow = 0;
		list<int>::iterator ia = a.num.begin();
		list<int>::const_iterator ib = b.num.begin();
		for (;; ia++, ib++)
		{
			if (ib == b.num.end())
			{
				while (borrow)
				{
					(*ia) -= borrow;
					borrow = 0;
					while (*ia < 0)
					{
						borrow++;
						*ia += 10000;
					}
					ia++;
				}
				while (a.num.size()>1 && a.num.back() == 0)
				{
					a.num.pop_back();
				}
				return a;
			}
			*ia -= (*ib) + borrow;
			borrow = 0;
			while (*ia < 0)
			{
				borrow++;
				*ia += 10000;
			}
		}
	}
	friend ostream& operator<<(ostream& out, const Bignum& b)
	{
		out << b.num.back();
		for (list<int>::const_reverse_iterator i = ++b.num.rbegin(); i != b.num.rend(); i++)
		{
			if (*i < 1000)
			{
				out << 0;
				if (*i < 100)
				{
					out << 0;
					if (*i < 10)
					{
						out << 0;
					}
				}
			}
			out << *i;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Bignum& b)
	{
		string input;
		in >> input;
		b.init(input);
		return in;
	}
	friend bool operator>(const Bignum& a, const Bignum& b)
	{
		if (a.num.size() == b.num.size())
		{
			list<int>::const_reverse_iterator ia = a.num.rbegin(), ib = b.num.rbegin();
			for (; ia != a.num.rend(); ia++, ib++)
			{
				if (*ia == *ib)
				{
					continue;
				}
				return *ia > *ib;
			}
		}
		return a.num.size() > b.num.size();
	}
};
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		Bignum Y;
		cin >> Y;
		cout << Bigsqrt(Y) << endl;
		if (n)
		{
			cout << endl;
		}
	}
}