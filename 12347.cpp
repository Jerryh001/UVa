#include<iostream>
using namespace std;
int arr[1000000];
void print(const int& start, const int& end)
{
	if (start > end) return;
	else if (start<end)
	{
		int newstart = start + 1;
		if (arr[start]>arr[end]|| arr[start]<arr[newstart])
		{
			print(newstart, end);
		}
		else
		{
			while (arr[start] > arr[newstart])
			{
				newstart++;
			}
			print(start + 1, newstart-1);
			print(newstart, end);
		}
	}
	cout << arr[start] << endl;
}
int main()
{
	int size = 0;
	for (; cin >> arr[size];size++);
	print(0, size-1);
}