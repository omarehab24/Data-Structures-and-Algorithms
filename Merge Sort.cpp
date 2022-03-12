
#include <iostream>
using namespace std;

void merge(int *, int, int, int);
void mergesort(int *, int, int);

int main()
{
	cout << "Size of the array = "; int size; cin >> size;

	int *A = new int[size];
	
	/*result in logically wrong input operation*/
	// cout << "Enter " << size << " random numbers to sort: \n"; int n; cin >> n;
	
	for (int i = 0; i < size; i++)
	{
		cin >> A[i];
	}

	mergesort(A, 0, size - 1);

	cout << endl << "After Sorting \n";

	for (int i = 0; i < size; i++)
		cout << A[i] << endl;

	return 0;
}

void mergesort(int *A, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(A, low, mid);
		mergesort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}

void merge(int *A, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	int *sorted = new int[high - low];

	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
			sorted[k++] = A[i++];

		else
			sorted[k++] = A[j++];
	}

	while (i <= mid)
		sorted[k++] = A[i++];

	while (j <= high)
		sorted[k++] = A[j++];

	for (k = low; k <= high; k++)
		A[k] = sorted[k];

}
