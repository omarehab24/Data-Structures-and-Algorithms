
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	int array[5];
	int i=0;

	ifstream in("student.txt");

	while (in >> array[i])
	{
		cout << array[i] << " ";
		i++;
	}
	in.close();

	cout << endl;

	cout << "Search for a number from the above: ";
	int x;
	if ( !(cin >> x) )
	{
		cout << "Please enter a number! \n";
		return -1;
	}
		
	cout << endl;

	int left = 0;
	int right = 5-1;
	int mid;
	int location = -1;

	while (true)
	{
		mid = (left + right) / 2;

		if (x == array[mid])
		{
			location = mid;
			cout << "Number is found at location: " << location + 1 << endl;
			break;
		}
	
		else if (x < array[mid])
			right = mid - 1;

		else if (x > array[mid])
			left = mid + 1;

	     if (left > right)
		{
			cout << "Number wasn't found!\n"; 
			break;
		}
	}

	cout << endl;

	return 0;
}
