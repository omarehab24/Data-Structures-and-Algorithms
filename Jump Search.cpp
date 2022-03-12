
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define size 12

int main()
{
	int number;
	int left, right, jump;
	int arr[size] = { 3, 5, 8, 15, 31, 51, 82, 144, 233, 382, 410,522 };
	cout << "enter your number: "; cin >> number;

	jump = sqrt(size);
	left = 0; right = 0;

	while (left < size&& arr[left] <= number)
	{
		right = min(left + jump, size - 1);

		if (number <= arr[right] && number >= arr[left])
			break;

		left += jump;

	}
	if (left >= size || number < arr[left])
	{
		cout << "number wasn't found!\n";
		return -1;
	}


	for (int i = left; i <= right && arr[i] <= number; i++)
	{
		if (arr[i] == number)
		{
			cout << "your number is at location " << i + 1 << endl;
			return 0;
		}

	}
	cout << "number wasn't found!\n";

	return 0;
}




