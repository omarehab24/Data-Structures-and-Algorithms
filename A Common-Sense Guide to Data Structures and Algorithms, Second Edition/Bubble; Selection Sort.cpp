#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <string>

using namespace std;
//#include <bits/stdc++.h> // all libraries //https://stackoverflow.com/questions/36761734/how-to-include-all-of-the-c-standard-library-at-once

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

void swap(int *arr1, int *arr2)
{
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void bubbleSort()
{
    int unsorted_until_index = array_size - 1;
    bool sorted = false;
    int steps = 0; // optional variable to measure how many steps it took for an array of 10 elements.

    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < unsorted_until_index; i++)
        {
            steps++; // comparison steps
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                steps++; // swapping steps
                sorted = false;
            }
        }
        unsorted_until_index -= 1;
    }
    cout << "steps = " << steps << endl;

    cout << "(Bubble sort)\n";
    display();
}

void selectionSort()
{
    for (int i = 0; i < array_size - 1; i++)
    {
        int lowestIndexNumber = i;
        for (int j = i + 1; j < array_size; j++)
        {
            if (a[j] < a[lowestIndexNumber])
                lowestIndexNumber = j;

            if (lowestIndexNumber != i)
                swap(a[i], a[lowestIndexNumber]);
        }
    }

    cout << "(Selection sort)\n";
    display();
}




int main()
{
    // RNGarray();
    //  bubbleSort();
    //  selectionSort();



}