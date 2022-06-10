#include <iostream>
#include <unordered_map>
#include <time.h>
using namespace std;

int a[5];
int array_size = sizeof(a) / sizeof(a[0]);

void display()
{
    for (const auto &i : a)
        cout << i << " ";

    cout << endl
         << endl;
}

void RNGarray()
{
    // int local_array_size = array_size;
    srand(time(NULL));
    for (int i = 0; i < array_size; i++)
        a[i] = rand() % 100 + 1;
    // a[i] = --local_array_size; // worst case scenario

    cout << "(RNG array)\n";
    display();
}

// Sorting array using quicksort
struct UnsortedArray
{
    int partition(int left_pointer, int right_pointer)
    {
        int pivot_index = right_pointer;
        int pivot = a[right_pointer];

        --right_pointer;

        while (true)
        {
            while (a[left_pointer] < pivot)
                left_pointer++;

            while (a[right_pointer] > pivot)
                right_pointer--;

            if (left_pointer >= right_pointer)
                break;
            else
                swap(a[left_pointer], a[right_pointer]);

            left_pointer++;
        }

        swap(a[left_pointer], a[pivot_index]);

        return left_pointer;
    }

    void quickSort(int left_index, int right_index)
    {

        if (right_index - left_index <= 0) // Base case: the subarray has 0 or 1 elements:
            return;

        int pivot_index = partition(left_index, right_index);

        quickSort(left_index, pivot_index - 1);
        quickSort(pivot_index + 1, right_index);
    }
    // see page 234
    int quickSelect(int nth_lowest_element, int left_index, int right_index)
    {
        if (right_index - left_index <= 0)
            return a[left_index];

        int pivot_index = partition(left_index, right_index);

        if (nth_lowest_element < left_index)
            quickSelect(nth_lowest_element, left_index, pivot_index - 1);
        else if (nth_lowest_element > right_index)
            quickSelect(nth_lowest_element, pivot_index + 1, right_index);
        // else // if (nth_lowest_element == pivot_index)

        return a[pivot_index];
    }
} unsorted_array;


int main(){
    
    RNGarray();

     cout << "(Quick sort)\n";
     unsorted_array.quickSort(0, array_size - 1);
     display();

     

   /*  cout << "(Quick select)\n";
      int value = unsorted_array.quickSelect(1, 0, array_size - 1); // in the first argument we search for the second-to-lowest value
      cout << value << endl;
      display(); */


    return 0;
}