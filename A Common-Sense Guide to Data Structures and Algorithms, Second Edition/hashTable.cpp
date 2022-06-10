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

void hashTable()
{                                  // hashtable has an O(1) read and insertion in average case, and O(N) in worst case
    unordered_map<int, bool> umap; // unordered map uses hash table
    for (int i : a)
        umap[i] = true; // assign each key a bool value which is true

    cout << "\n\n";

    for (int i : a)
        cout << umap[i] << " "; // when we lookup each key in this map, we'll get 1 as a value, which is true in boolean
}

int main()
{

    RNGarray();
    hashTable();
}
