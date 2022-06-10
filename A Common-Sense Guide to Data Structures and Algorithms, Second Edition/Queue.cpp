#include <iostream>
#include <string>
#include "DoublyLinkedList.cpp"
using namespace std;

class Queue
{

    DoublyLinkedList node;

public:
    void enqueue(string element)
    {

        node.insertAtEnd(element);
    }

    void dequeue()
    {
        if (isEmpty())
            return;

        node.removeFromFront();
    }

    void read()
    {
        if (isEmpty())
            return;

        cout << "Front element: " << node.first_node->node << endl;
    }

    bool isEmpty()
    {
        if (node.first_node == NULL)
        {
            cout << "Queue is empty!\n";
            return true;
        }
        
        return false;
    }
};

int main()
{

    Queue queue;
    queue.enqueue("White");
    queue.enqueue("Grey");
    queue.enqueue("Orange");
    queue.read();
    queue.dequeue();
    queue.read();

    return 0;
}