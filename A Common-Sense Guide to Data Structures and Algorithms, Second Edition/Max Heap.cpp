#include <iostream>
#include <string>
using namespace std;

struct Heap
{

    int size;
    static inline int count = 0;
    int arr[10]{0};

    // int first_node;
    // int last_node;

    /*  Heap(int size_argument = 0) {
         size = size_argument;
     }; */

    // Heap(int *arr_argument = nullptr, int size_argument = 0) : arr(arr_argument), size(size_argument) {};

    int getFirstNode(int first_node)
    {
        return arr[0] = first_node;
    }

    int getLastNode(int last_node)
    {
        return arr[size - 1] = last_node;
    }
    // To find the left child of any node, we can use the formula, (index * 2) + 1
    int leftChildIndex(int index)
    {
        return (index * 2) + 1;
    }

    // To find the left child of any node, we can use the formula, (index * 2) + 2
    int rightChildIndex(int index)
    {
        return (index * 2) + 2;
    }

    // To find a node’s parent, we can use the formula, (index - 1) / 2
    int parentIndex(int index)
    {
        return ((index - 1) / 2);
    }

    // See page 312
    void insert(int value)
    {
        count++;
        // arr = new int[size];
        // size = 3;
        arr[count - 1] = value; // Turn value into last node by inserting it at the end of the array:
        int new_node_index = count - 1;

        // The main condition is that the new node is greater than its parent node.
        while ((new_node_index > 0) && (arr[new_node_index] > arr[parentIndex(new_node_index)]))
        {
            swap(arr[parentIndex(new_node_index)], arr[new_node_index]); // Each time this loop runs, we swap the new node with its parent node
            new_node_index = parentIndex(new_node_index);
        }
        /* new_node_index = parentIndex(new_node_index);
        if(arr[leftChildIndex(new_node_index)] < arr[rightChildIndex(new_node_index)])
            swap(arr[leftChildIndex(new_node_index)], arr[rightChildIndex(new_node_index)]); */
    }

    // See page 313
    void deleteNode()
    {

        arr[0] = arr[count - 1];
        count--;
        int trickle_node_index = 0;

        while (hasGreaterChild(trickle_node_index))
        {

            int larger_child_index = largerChildIndex(trickle_node_index);

            swap(arr[trickle_node_index], arr[larger_child_index]);

            trickle_node_index = larger_child_index;
        }
    }

    bool hasGreaterChild(int index)
    {
        if (arr[leftChildIndex(index)] || arr[rightChildIndex(index)] > arr[index])
            return true;
        else
            return false;
    }

    int largerChildIndex(int index)
    {
        if (arr[rightChildIndex(index)] == 0)
            return leftChildIndex(index);

        if (arr[rightChildIndex(index)] > arr[leftChildIndex(index)])
            return rightChildIndex(index);
        else
            return leftChildIndex(index);
    }

    void traverse()
    {
        cout << "(Heap)\n";
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    // O(log N) for insertions and deletions.
    Heap heap; // in max-heap, root node (first index) is always the greatest value.
    heap.insert(88);
    heap.insert(100);
    heap.insert(25);
    heap.insert(16);
    heap.insert(87);
    heap.traverse();
    heap.deleteNode();
    heap.traverse();
    heap.insert(180);
    heap.traverse();

    return 0;
}