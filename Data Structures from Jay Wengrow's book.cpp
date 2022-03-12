/*Code from Jay Wengrow's book: A Common-Sense Guide to Data Structures and Algorithms, Second Edition: Level Up Your Core Programming Skills - 2nd Edition*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <string>
//#include <bits/stdc++.h> // all libraries //https://stackoverflow.com/questions/36761734/how-to-include-all-of-the-c-standard-library-at-once
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

void hashTable()
{                                  // hashtable has an O(1) read and insertion in average case, and O(N) in worst case
    unordered_map<int, bool> umap; // unordered map uses hash table
    for (int i : a)
        umap[i] = true; // assign each key a bool value which is true

    cout << "\n\n";

    for (int i : a)
        cout << umap[i] << " "; // when we lookup each key in this map, we'll get 1 as a value, which is true in boolean
}

int factorial(int n)
{               // In recursion terminology, the case in which our function will not recurse is known as the base case. So, 1 is the base case for our factorial() function.
    if (n == 1) // Base case where factorial 1 returns 1
        return 1;

    return n * factorial(n - 1);
    // e.g. factorial(3)
    // { 3 * factorial(2) }
    // { 2 * factorial(1) }
    // { 1 }
    // { 2 * 1 }
    // { 3 * 2 * 1 }
    // factorial(3) == 6
}

void doubledArray(int arr[], int index = 0) // int index = 0 is the default parameter
{
    if (index > array_size) // Base case
    {
        cout << "(Doubled Array)\n";
        display();
        return;
    }

    arr[index] *= 2;
    doubledArray(arr, ++index);
}

int arraySum(int *arr, int *end = nullptr)
{
    // cout << "Recursion\n";
    end = &arr[array_size - 1];

    if (*arr == *end) // base case
        return arr[0];

    return arr[0] + arraySum(arr + 1, end); // arraySum(arr+1, end) is the subproblem
    // during each iteration in the subproblem, arr[0] is the arr+1, which is the next element, we keep adding the elements together until we arr[0] is the last element.
}

// Alternative arraySum()
/* int arraySum(int *arr)
{
    if (*arr == arr[array_size-1])
        return 0;

    return *arr + arraySum(arr+1);
} */

// fibonacci of the n'th element, fibonacci starts with the element 0, e.g. 0,1,1,2,3,5,...
// fibonacci using normal recursion
/* int fib(int n)
{
cout << "Recursionn\n";

if (n == 0 || n == 1)
    return n;

return fib(n-2) + fib(n-1);
} */

// fibonacci using memoization
// O(N)
/* int fib(int n, unordered_map<int,int> memo = {})
{
cout << "Recursion\n";

if (n == 0 || n == 1)
    return n;

if (!memo[n]) // see page 209
    return memo[n] = fib(n-2, memo) + fib(n-1, memo);

return memo[n];
} */

// fibonacci using the bottom-up approach
// O(N)
int fib(int n)
{

    int a = 0;
    int b = 1;
    int temp;

    for (int i = 1; i < n; i++)
    {
        temp = a;
        a = b;
        b = temp + a;
    }

    return b;
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
    int quickSelect(int nth_lowest_element, int left_index, int right_index){
        if (right_index - left_index <= 0)
            return a[left_index];

        int pivot_index = partition(left_index, right_index);
            
        if (nth_lowest_element < left_index)
            quickSelect(nth_lowest_element, left_index, pivot_index-1);
        else if (nth_lowest_element > right_index)
            quickSelect(nth_lowest_element, pivot_index+1, right_index);
        //else // if (nth_lowest_element == pivot_index)

        return a[pivot_index];
    }
} unsorted_array;

struct Node
{
    string node;
    Node *next = NULL;
    Node* prev = NULL;

    Node(string node){
        this->node = node;
    }
};

class LinkedList{
    Node *first_node = NULL;
    
public:
    LinkedList(Node *first_node_argument) : first_node(first_node_argument) {}

    // O(N)
    void traverse(){
        Node *current_node = first_node;

        cout << "(Linked List)\n";
        while(current_node != nullptr){
                cout << current_node->node << " ";
                current_node = current_node->next;
            }
        cout << endl <<endl;
    }

    // O(N)
    void readValue(int index){
        Node *current_node = first_node;
        int current_index = 0;

        while(current_index < index){

            if(current_node == NULL){
                cout << "Doesn't exist\n";
                return;
            }

            current_node = current_node->next;
            current_index++;

        }
            cout <<"Linked list read value = " << current_node->node << endl;
    }

    // O(N)
    void search(string value){
        Node *current_node = first_node;
        int current_index = 0;

        while(current_node != nullptr){
            if(current_node->node == value){
                cout <<"Linked list search value = " << current_index << endl;
                return;
            }

            current_node = current_node->next;
            current_index++;
        }
        cout << "Doesn't exist\n";
    }

    // O(1) for best-case scenario (Insertion at the beginning), O(N) for worst-case scenario (Insertion at the end)
    void insertAtIndex(int index, string value){
        Node *new_node = new Node(value);

        if(index == 0){ // at the beginning of the list // O(1)
            new_node->next = first_node;
            first_node = new_node; // first node now points to new node
        }

        Node *current_node = first_node;
        int current_index = 0;

        while(current_index < index-1){
            current_node = current_node->next;
            current_index++;

            if(current_node == NULL){
                cout << "Error!\n";
                return;
            }
        }

        new_node->next = current_node->next;
        current_node->next = new_node;

    }

    // O(1) for best-case scenario, O(N) for worst-case scenario (Same as insertion)
    void deleteAtIndex(int index){
    
        if(index == 0){
            first_node = first_node->next; 
            return;
        }

        Node *current_node = first_node;
        int current_index = 0;

        while(current_index < index-1){
            current_node = current_node->next;
            current_index++;

            if(current_node == NULL){
                cout << "Error!\n";
                return;
            }
        }
        Node *temp_node = current_node->next->next;
        current_node->next = temp_node;
        temp_node = NULL;
    }
};

class DoublyLinkedList{

    Node *first_node = nullptr, *last_node = nullptr;

public:

    DoublyLinkedList(){}

    DoublyLinkedList(Node *first_node_argument, Node *last_node_argument) 
    {
        first_node = first_node_argument;
        last_node = last_node_argument;
    }

    friend class Queue;

    void insertAtEnd(string value){
        Node *new_node = new Node(value);

        if(first_node == nullptr){ // If there are no elements yet in the linked list:
            first_node = last_node = new_node;
        }
        else { // If the linked list already has at least one node:
            new_node->prev = last_node;
            last_node->next = new_node;
            last_node = new_node;
        }
    }

    void removeFromFront(){
        Node* removed_node = first_node;
        first_node = first_node->next;
        removed_node = nullptr;
    }

};

class Queue{

    DoublyLinkedList node;

public:

    void enqueue(string element){
       
         node.insertAtEnd(element);
    }

    void dequeue(){
          if(isEmpty())
            return;

         node.removeFromFront();
    }

    void read(){
        if(isEmpty())
            return;

        cout << "Front element: " << node.first_node->node << endl;
    }

    bool isEmpty(){
        if(node.first_node == NULL){
            cout << "Queue is empty!\n";
            return true;
        }
    }

};

class TreeNode{
    int value;
    TreeNode *left_node,*right_node;

    public:
        TreeNode(int value, TreeNode *left_node = nullptr, TreeNode *right_node = nullptr){
            this->value = value; // Reminder: "this" is a pointer to an object
            this->left_node = left_node;
            this->right_node = right_node;
        }

    friend class BinarySearchTree;
};

class BinarySearchTree{

public:
    // See page 270
    // O(Log N)
    void searchNode(int search_value, TreeNode *node) // TreeNode *node is the current node
    {

        if(node == nullptr){
            cout << "Node not found!\n";
            return;
        }
        else if(node->value == search_value){
            cout << "Node found: " <<  node->value << endl;
            return;
        }
        else if(search_value < node->value)
            searchNode(search_value, node->left_node);
        else
            searchNode(search_value, node->right_node);

    }

    // O(log N)
    void insertNode(int new_value, TreeNode *node){

        if(new_value < node->value){
            if(node->left_node == nullptr) // This is the base case
                node->left_node = new TreeNode(new_value);
            else
                insertNode(new_value, node->left_node);
        }

        if(new_value > node->value){ // This is the base case
            if(node->right_node == nullptr)
                node->right_node = new TreeNode(new_value);
            else
                insertNode(new_value, node->right_node);
        }
    }

    // See page 281
    // O(log N)
    TreeNode* deleteNode(int value_to_delete, TreeNode *node){
        
        if(node == NULL)
            return NULL;

        else if(value_to_delete < node->value)
            node->left_node = deleteNode(value_to_delete, node->left_node);
            
        else if(value_to_delete > node->value)
            node->right_node = deleteNode(value_to_delete, node->right_node);
            
        else if(value_to_delete == node->value){

            if(node->left_node == NULL)
                return node->right_node;
            else if(node->right_node == NULL)
                return node->left_node;
            else{
                // https://www.programiz.com/dsa/binary-search-tree
                TreeNode *temp_node = lift(node->right_node); // find the successor
                node->value = temp_node->value;
                node->right_node = deleteNode(temp_node->value ,node->right_node); // delete the temp node
            }
        }
                return node;
    }

private:
    TreeNode* lift(TreeNode *node){

        if(node->left_node != NULL)
            node->left_node = lift(node->left_node);
        
        return node;
    }

public:
    // See page 288
    // O(N)
    void traverseTree(TreeNode *node){

        if(node == NULL) // Base case // Once we reach the base case, this function will be popped off the call stack.
            return;

        // inorder traversal (ascending order)
        traverseTree(node->left_node); // keep recursing until we reach the base case, then this function's instance will be popped off the call stack. then continue on to the next line of code
        cout << node->value << " ";
        traverseTree(node->right_node);
    }

};

struct Heap{

    int size;
    static inline int count = 0;
    int arr[10]{0};
    
    
    //int first_node;
    //int last_node;

   /*  Heap(int size_argument = 0) {
        size = size_argument;
    }; */

    //Heap(int *arr_argument = nullptr, int size_argument = 0) : arr(arr_argument), size(size_argument) {};

    int getFirstNode(int first_node){
        return arr[0] = first_node;
    }

    int getLastNode(int last_node){
        return arr[size-1] = last_node;
    }
    // To find the left child of any node, we can use the formula, (index * 2) + 1 
    int leftChildIndex(int index){
        return (index * 2) + 1;
    }

    // To find the left child of any node, we can use the formula, (index * 2) + 2
    int rightChildIndex(int index){
        return (index * 2) + 2;
    }

    // To find a node’s parent, we can use the formula, (index - 1) / 2
    int parentIndex(int index){
        return ((index - 1) / 2);
    }

    // See page 312
    void insert(int value){
        count++;
        //arr = new int[size];
        //size = 3;
        arr[count-1] = value; // Turn value into last node by inserting it at the end of the array:
        int new_node_index = count-1;

        // The main condition is that the new node is greater than its parent node.
        while( (new_node_index > 0) && (arr[new_node_index] > arr[parentIndex(new_node_index)]) )
        {
            swap(arr[parentIndex(new_node_index)], arr[new_node_index]); // Each time this loop runs, we swap the new node with its parent node
            new_node_index = parentIndex(new_node_index);
           
        } 
        /* new_node_index = parentIndex(new_node_index);
        if(arr[leftChildIndex(new_node_index)] < arr[rightChildIndex(new_node_index)])
            swap(arr[leftChildIndex(new_node_index)], arr[rightChildIndex(new_node_index)]); */
    }

    // See page 313
    void deleteNode(){

        arr[0] = arr[count-1];
        count--;
        int trickle_node_index = 0;

        while(hasGreaterChild(trickle_node_index)){

            int larger_child_index = largerChildIndex(trickle_node_index);

            swap(arr[trickle_node_index], arr[larger_child_index]);

            trickle_node_index = larger_child_index;
        }

    }

    bool hasGreaterChild(int index){
        if(arr[leftChildIndex(index)] || arr[rightChildIndex(index)] > arr[index])
            return true;
        else 
            return false;
    }

    int largerChildIndex(int index){
        if(arr[rightChildIndex(index)] == 0)
            return leftChildIndex(index);
        
        if(arr[rightChildIndex(index)] > arr[leftChildIndex(index)])
            return rightChildIndex(index);
        else
            return leftChildIndex(index);
    }

    void traverse(){
        cout << "(Heap)\n";
        for(int i=0; i<count; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    //RNGarray();
    // bubbleSort();
    // selectionSort();
    //  hashTable();
    // int m = 5; cout << "Factorial " << m << " = " << factorial(n);
    // doubledArray(a);
    // cout << "Array sum = " << arraySum(a) << endl;
    // int x = 10; cout << "Fibonacci of the " << x << "th element = " << fib(x);

   /*  cout << "(Quick sort)\n";
    unsorted_array.quickSort(0, array_size - 1);
    display(); */

  /*   cout << "(Quick select)\n";
    int value = unsorted_array.quickSelect(1, 0, array_size - 1); // in the first argument we search for the second-to-lowest value 
    cout << value << endl;
    display(); */

/*     Node node1("Blue"), node2("Red"), node3("Green"), node4("Black");
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    LinkedList linked_list(&node1);

    //linked_list.insertAtIndex(4, "Brown");
    linked_list.deleteAtIndex(0);
    linked_list.traverse();
    linked_list.readValue(0);
    linked_list.search("Red"); */
   
 /*    Queue queue;
    queue.enqueue("White");
    queue.enqueue("Grey");
    queue.enqueue("Orange");
    queue.read();
    queue.dequeue();
    queue.read(); */

  /*   TreeNode tree_node1(25), tree_node2(75);
    TreeNode root_node(50, &tree_node1, &tree_node2);

    printf("(Binary Search Tree)\n");
    BinarySearchTree node;
    node.searchNode(5, &root_node);
    node.insertNode(100, &root_node);
    node.searchNode(100, &root_node);
    node.insertNode(0, &root_node);
    node.searchNode(0, &root_node);
    node.traverseTree(&root_node);
    node.deleteNode(50, &root_node);
    cout << endl;
    node.traverseTree(&root_node); */

/*     // O(log N) for insertions and deletions.
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
    heap.traverse(); */

    

}