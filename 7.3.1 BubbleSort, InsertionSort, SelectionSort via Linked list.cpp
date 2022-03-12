/*Write C++ program to implement linked list to insert these elements (20,10,77,200,17)
then:
• Use insertion sort to sort the elements of the linked list (make function called insertion_sort_Link).
• Use selection sort to sort the elements of the linked list (make function called selection_sort_Link).
• Use Bubble sort to sort the elements of the linked list (make function called Bubble_sort_Link).*/

#include <iostream>
#include <conio.h>
using namespace std;

void displaylist();
void linkedlist();
void bubblesort();
void selectionsort();
void insertionsort();

struct node
{
	int number;
	node*next;
	node*prev;
};
node*head = nullptr;
node*tail = nullptr;
node*current = nullptr;
node*i = new node;
node*j = new node;

int temp;

int main()
{
	system("color F0");
	linkedlist();
	cout << "LinkedList: \n";
	displaylist();

	char button ;
		cout << "b. Bubble sort\n";
		cout << "s. Selection sort\n";
		cout << "i. Insertion sort\n\n";
		button = _getch();

		switch (button)
		{
		case'b':
			cout <<"Bubble sort: \n";
			bubblesort();
			displaylist();
			break;

		case's':
			cout << "Selection sort: \n";
			selectionsort();
			displaylist();
			break;

		case'i':
			cout << "Insertion sort: \n";
			insertionsort();
			displaylist();
			break;

		default:
			cout << "Enter one of the shown buttons!\n\n";
			break;
		}
    return 0;
}

void linkedlist()
{
	int numbers[5] = { 20,10,77,200,17 };

	for (int k = 0; k < 5; k++)
	{
		current = new node;
		current->number = numbers[k];
		current->next = nullptr;

		if (head == nullptr)
		{
			head = current;
			tail = current;
		}
		else
		{
			tail->next = current;
			current->prev = tail;
			tail = current;
		}
	}
}
void displaylist()
{
	current = head;
	while (current != nullptr)
	{
		cout << current->number << endl;
		current = current->next;
	}
	cout << endl;
}
void bubblesort()
{
	for (i = head; i != tail; i = i->next)
	{
		for (j = head; j != tail; j = j->next)
		{
			if (j->number > j->next->number)
			{
				temp = j->number;
				j->number = j->next->number;
				j->next->number = temp;
			}
		}
	}
}
void selectionsort()
{
	for (i = head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->number > j->number)
			{
				temp = i->number;
				i->number = j->number;
				j->number = temp;
			}
		}
	}
}
void insertionsort()
{
	for (i = head->next; i != NULL; i = i->next)
	{
		for (j = i; j != head; j = j->prev)
		{
			if (j->number < j->prev->number)
			{
				temp = j->number;
				j->number = j->prev->number;
				j->prev->number = temp;
			}
		}
	}
}
