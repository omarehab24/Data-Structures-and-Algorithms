/*Write a C++ Program to implement Circular Singly linked list with its basic operations as following insert, display, delete a node and destroy the list.*/

#include "stdafx.h"
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

	while (button != 27)
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
	current->next = nullptr;

	if (head == NULL)
	{
		head = current;
		tail = current;
		head->next = head;
	}
	else
	{
		current->next = head;
		head = current;
		tail->next = current;
	}
}


void insert_to_tail(int num)
{
	current = new node;
	current->data = num;
	current->next = nullptr;

	if (tail == NULL)
	{
		head = current;
		tail = current;
		tail->next = head;
	}
	else
	{
		current->next = tail->next;
		tail->next = current;
		tail = current;
	}
	
}

void delete_node(int num)
{
	node*temp;
	if (head == NULL)//if the list is empty
	{
		cout << "The List is empty!\n\n";
		return;
	}

	if (head->data == num && head == tail)//if there is only one value
	{
		delete head;
		head = nullptr;
		cout << "Done!\n\n";
		return;
	}
		
	if (head->data == num)//if we want to delete the first node
	{
		temp = head;
		head = head->next;
		tail->next = head;
		delete temp;
		cout << "Done!\n\n";
		return;
	}

	if (tail->data == num)//if we want to delete the last node
	{
		temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = tail->next;
		delete tail;
		tail = temp;
		cout << "Done!\n\n";
		return;
	}

	temp = current = head;
	
	do
	{
		temp = current;
		current = current->next;
		if (current->data == num)
		{
			temp->next = current->next;
			delete current;
			cout << "Done!\n\n";
			return;
		}
	} while (current != head);

	cout << "Number wasn't found!\n\n";
		
}

void delete_list()
{
	if (head == NULL)
		cout << "The list is empty!\n\n";

	current = head;
	do
	{
		head = head->next;
		delete current;
		current = head;
	}while (current != head);
	head = NULL;
	tail = NULL;

	cout << "The list is deleted successfully!\n\n";
}

void print_list()
{
	node*temp = head;
	if (head == NULL)
		cout << "The list is empty!\n\n";
	else
	{
		cout << "List contains: \n";
		temp = head;
		do
		{
			cout << temp->data << endl;
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
	
}

