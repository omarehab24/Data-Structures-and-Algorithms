
#include <iostream>
using namespace std;
#define size 12

int main()
{
	int number;
	int mid = 0;
	int left = 0;
	int right = size - 1;
	int loc = -1;

	int arr[size] = { 3, 5, 8, 15, 31, 51, 82, 144, 233, 382, 410,522 };
	cout << "Enter the element to be searched\n";
	cin >> number;

	while (left <= right && number >= arr[left] && number <= arr[right])
	{
		mid = left + (right - left) * (number - arr[left]) / (arr[right] - arr[left]);

		if (arr[mid] == number)
		{
			loc = mid;
			cout << "The number is at location " << loc + 1 << endl;
			return mid;
		}

		if (number < arr[mid])
			right = mid - 1;

		else if (number > arr[mid])
			left = mid + 1;
	}

	cout << "The number wasn't found!\n";




	return 0;
}
