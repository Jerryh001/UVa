#include<iostream>
#include<string>
using namespace std;
string input_old = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`-=[]\\;\',./ ";
string input_new = "0VXSWDFGUHJKNBIO0EARYCQZT09`1234567800-P[]L;M,. ";
string input;
int main()
{
	while (getline(cin, input))
	{
		for (int i = 0; i < input.size(); i++)
		{
			int local = input_old.find_first_of(input[i]);
			cout << input_new[local];
		}
		cout << endl;
	}
}