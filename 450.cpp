#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct member
{
	string Title;
	string FirstName;
	string LastName;
	string HomeAddress;
	string Department;
	string HomePhone;
	string WorkPhone;
	string CampusBox;
};
int main()
{
	int deptN;
	vector<member> memberlist;
	cin >> deptN;
	cin.get();
	while (deptN--)
	{
		string dept;
		getline(cin, dept);
		while (1)
		{
			member M;
			char test = cin.get();
			if (test == '\n' || cin.eof())
			{
				break;
			}
			M.Department = dept;
			getline(cin, M.Title, ',');
			M.Title = test + M.Title;
			getline(cin, M.FirstName, ',');
			getline(cin, M.LastName, ',');
			getline(cin, M.HomeAddress, ',');
			getline(cin, M.HomePhone, ',');
			getline(cin, M.WorkPhone, ',');
			getline(cin, M.CampusBox, '\n');
			memberlist.push_back(M);
		}
	}
	for (int i = 0; i < memberlist.size() - 1; i++)
	{
		for (vector<member>::iterator j = memberlist.begin(); j < memberlist.end() - i - 1; j++)
		{
			if (j->LastName > (j + 1)->LastName)
			{
				swap(*j, *(j + 1));
			}
			else if (j->LastName == (j + 1)->LastName&&j->FirstName > (j + 1)->FirstName)
			{
				swap(*j, *(j + 1));
			}
		}
	}
	for (vector<member>::iterator i = memberlist.begin(); i != memberlist.end(); i++)
	{
		cout << "----------------------------------------" << endl
			<< i->Title << " "
			<< i->FirstName << " "
			<< i->LastName << endl
			<< i->HomeAddress << endl
			<< "Department: " << i->Department << endl
			<< "Home Phone: " << i->HomePhone << endl
			<< "Work Phone: " << i->WorkPhone << endl
			<< "Campus Box: " << i->CampusBox << endl;
	}
}
