#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<cmath>
#include<cctype>
#include<map>
using namespace std;
int main()
{
	
	string temp;
	string notneed = ",.:;!?\"()\t\n";
	while (1)
	{
		map<string, int> words;
		int landa = 0;
		double ET = 0;
		double Erel = 0;;
		stringstream ins;
		while (1)
		{
			getline(cin, temp);
			if (temp == "****END_OF_TEXT****") break;
			else if (temp == "****END_OF_INPUT****") return 0;
			for (int i = 0; i < signed(temp.size()); i++)
			{
				for (int j = 0; j < signed(notneed.size()); j++)
				{
					if (temp[i] == notneed[j])
					{
						temp[i] = ' ';
					}
				}
				if (isupper(temp[i]))
				{
					temp[i] = tolower(temp[i]);
				}
			}
			ins << temp << " ";
		}
		while (1)
		{
			ins >> temp;
			if (ins.eof()) break;
			words[temp]++;
			landa++;
		}
		for (map<string, int>::iterator i = words.begin(); i != words.end(); i++)
		{
			ET += (i->second)*(log10(landa) - log10(i->second));
		}
		ET /= landa;
		Erel = ET * 100 / log10(landa) ;
		cout << fixed<<setprecision(0)<<landa << " " << setprecision(1) << ET << " " << setprecision(0) << round(Erel) << endl;
	}
}