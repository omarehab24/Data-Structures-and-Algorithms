#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string node;
    Node *next = NULL;
    Node *prev = NULL;

    Node(string node)
    {
        this->node = node;
    }
};

class DoublyLinkedList
{

    Node *first_node = nullptr, *last_node = nullptr;

public:
    DoublyLinkedList() {}

    DoublyLinkedList(Node *first_node_argument, Node *last_node_argument)
    {
        first_node = first_node_argument;
        last_node = last_node_argument;
    }

    friend class Queue;

    void insertAtEnd(string value)
    {
        Node *new_node = new Node(value);

        if (first_node == nullptr)
        { // If there are no elements yet in the linked list:
            first_node = last_node = new_node;
        }
        else
        { // If the linked list already has at least one node:
            new_node->prev = last_node;
            last_node->next = new_node;
            last_node = new_node;
        }
    }

    void removeFromFront()
    {
        Node *removed_node = first_node;
        first_node = first_node->next;
        removed_node = nullptr;
    }
};
