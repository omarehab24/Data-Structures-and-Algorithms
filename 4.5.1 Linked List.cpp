/*Write C++ program to implement the basic operations of Linked List as we discussed above, through creating menu to handle different operations and if the user wants to quit s/he must press escape button from the keyboard.*/

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void insert_to_head(int);
void insert_to_tail(int);
void delete_node(int);
void delete_list();
void print_list();

struct node {
	int data;
	node * next;
};

node*head = 0;
node*tail = 0;
node*current = 0;

int main()
{
	int button = 0;
	int value = 0;
	cout << "**Create a simple Linked list of numbers**\n" << "-------------------------------------------\n";

	while (button != 27) // ESC Button
	{
		cout << "1. to add a number to the head of the list.\n";
		cout << "2. to add a number to the tail of the list.\n";
		cout << "3. to display the list.\n";
		cout << "4. delete a number you added.\n";
		cout << "5. to delete the whole list.\n";
		cout << "Press ESC to exit!\n\n";

		button = _getch(); //_getch () reads a single byte character as input.

		switch (button)
		{
		case '1':
			cout << "Enter a number to head: "; cin >> value;
			insert_to_head(value);
			cout << "Done!\n\n";
			break;

		case '2':
			cout << "Enter a number to tail: "; cin >> value;
			insert_to_tail(value);
			cout << "Done!\n\n";
			break;

		case '3':
			print_list();
			break;

		case '4':
			cout << "Enter the number you want to delete: "; cin >> value;
			delete_node(value);
			break;

		case '5':
			delete_list();
			break;

		case 27:
			break;

		default:
			cout << "please enter one of the displayed buttons!\n\n";
			break;
		}
	}

	return 0;
}

void insert_to_head(int num)
{
	current = new node;
	current->data = num;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		current->next = head;
		head = current;
	}
}


void insert_to_tail(int num)
{
	current = new node;
	current->data = num;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		tail->next = current;
		tail = tail->next;
	}
}

void delete_node(int num)
{
	node*temp; /*temp pointer to maintain the linked list*/
	if (head == NULL)
	{
		cout << "The List is empty!\n\n";
		return;
	}

	temp = current = head;
	if (current->data == num)
	{
		head = head->next;
		delete current;
		cout << "Deleted Successfully!\n\n";
		return;

	}
	while (current != NULL&& current->data != num)
	{
		temp = current;
		current = current->next;
	}
	if (current == NULL)
	{
		cout << "Number wasn't found!\n\n";
	}

	else
	{
		temp->next = current->next;
		delete current;
		cout << "Deleted Successfully!\n\n";
	}

}


void delete_list()
{
	if (head == NULL)
	{
		cout << "The list is empty!\n\n";
		return;
	}
		

	current = head;
	while (current != NULL)
	{
		head = head->next;
		delete current;
		current = head;
	}
	head = NULL;
	tail = NULL;

	cout << "The list is deleted successfully!\n\n";
}

void print_list()
{
	if (head == NULL)
		cout << "The list is empty!\n\n";
	else
	{
		cout << "List contains: \n";
		current = head;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
		cout << endl;
	}
}
