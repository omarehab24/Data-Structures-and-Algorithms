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

class LinkedList
{
    Node *first_node = NULL;

public:
    LinkedList(Node *first_node_argument) : first_node(first_node_argument) {}

    // O(N)
    void traverse()
    {
        Node *current_node = first_node;

        cout << "(Linked List)\n";
        while (current_node != nullptr)
        {
            cout << current_node->node << " ";
            current_node = current_node->next;
        }
        cout << endl
             << endl;
    }

    // O(N)
    void readValue(int index)
    {
        Node *current_node = first_node;
        int current_index = 0;

        while (current_index < index)
        {

            if (current_node == NULL)
            {
                cout << "Doesn't exist\n";
                return;
            }

            current_node = current_node->next;
            current_index++;
        }
        cout << "Linked list read value = " << current_node->node << endl;
    }

    // O(N)
    void search(string value)
    {
        Node *current_node = first_node;
        int current_index = 0;

        while (current_node != nullptr)
        {
            if (current_node->node == value)
            {
                cout << "Linked list search value = " << current_index << endl;
                return;
            }

            current_node = current_node->next;
            current_index++;
        }
        cout << "Doesn't exist\n";
    }

    // O(1) for best-case scenario (Insertion at the beginning), O(N) for worst-case scenario (Insertion at the end)
    void insertAtIndex(int index, string value)
    {
        Node *new_node = new Node(value);

        if (index == 0)
        { // at the beginning of the list // O(1)
            new_node->next = first_node;
            first_node = new_node; // first node now points to new node
        }

        Node *current_node = first_node;
        int current_index = 0;

        while (current_index < index - 1)
        {
            current_node = current_node->next;
            current_index++;

            if (current_node == NULL)
            {
                cout << "Error!\n";
                return;
            }
        }

        new_node->next = current_node->next;
        current_node->next = new_node;
    }

    // O(1) for best-case scenario, O(N) for worst-case scenario (Same as insertion)
    void deleteAtIndex(int index)
    {

        if (index == 0)
        {
            first_node = first_node->next;
            return;
        }

        Node *current_node = first_node;
        int current_index = 0;

        while (current_index < index - 1)
        {
            current_node = current_node->next;
            current_index++;

            if (current_node == NULL)
            {
                cout << "Error!\n";
                return;
            }
        }
        Node *temp_node = current_node->next->next;
        current_node->next = temp_node;
        temp_node = NULL;
    }
};

int main()
{

    Node node1("Blue"), node2("Red"), node3("Green"), node4("Black");
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    LinkedList linked_list(&node1);

    linked_list.traverse();
    // linked_list.insertAtIndex(4, "Brown");
    linked_list.deleteAtIndex(0);
    linked_list.traverse();
    linked_list.readValue(0);
    linked_list.search("Red");

    return 0;
}