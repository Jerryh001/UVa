#include<iostream>
//#include<fstream>
#include<list>
#include<vector>
using namespace std;
class Bignum
{
	list<int> num;
public:
	Bignum()
	{

	}
	Bignum(int i)
	{
		num.push_back(i);
	}
	friend void muti(Bignum& ans, const Bignum& a, const int& n)
	{
		ans = a;
		int carry = 0;
		
		for (list<int>::iterator i = ans.num.begin();i!=ans.num.end(); i++)
		{
			*i = (*i) * n+carry;
			carry = *i / 10000;
			*i%= 10000;
		}
		if (carry)
		{
			ans.num.push_back(carry);
		}
		return;
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
	B.resize(1001);
	B[0] = 1;
	B[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		muti(B[i], B[i - 1], i);
		//B[i]=B[i-1]*i
		//cout << B[i] << endl;
	}
	int a;
	while (1)
	{
		cin >> a;
		if (cin.eof()) return 0;
		cout << a << "!"<<endl << B[a] << endl;
	}
	//cout << B[5000] << endl;
}


