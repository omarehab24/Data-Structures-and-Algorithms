
#include <iostream>
using namespace std;
#define array_size 5

void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void selectionSort(int (&arr)[array_size]) // equivalent to *arr
{
    for (int i = 0; i < array_size-1; i++)
    {
        int lowestIndexNumber = i;
        for (int j = i + 1; j < array_size; j++)
        {
            if (arr[j] < arr[lowestIndexNumber])
                lowestIndexNumber = j;
        }
        if (lowestIndexNumber != i)
            swap(&arr[i], &arr[lowestIndexNumber]);
    }
}

int main()
{
	int array[array_size] = {3,1,5,2,4};
	int mid = 0;;
	int l = 0;
	int r = array_size - 1;
	int loc = -1;
	int item;

/* 	cout << "Enter the elements: \n";
	for (int i = 0; i < size; i++)
		cin >> array[i]; */

	selectionSort(array);

	cout << "What's the number you're looking for ?\t";
	cin >> item;

	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (item == array[mid])
		{
			loc = mid;
			cout << "Item is found at location " << loc + 1 << endl;
			return 0;
		}

		 if (array[mid] < item)
			l = mid + 1;

	     else
			r = mid - 1;
            
	/* 	else if (l > r && item != array[mid])
		{
			cout << "item wasn't found!\n";
			break;
		} */


	}
    cout << "item wasn't found!\n";



	return 0;
}
