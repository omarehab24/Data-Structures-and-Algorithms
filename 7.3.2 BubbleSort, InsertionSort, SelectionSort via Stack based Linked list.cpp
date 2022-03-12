/*Write C++ program to implement stack based linked list to push these elements (300,100,500,200,400)
then: 
• Use insertion sort to sort the elements of the stack (make function called insertion_sort_Stack).
• Use selection sort to sort the elements of the stack (make function called selection_sort_Stack).
• Use Bubble sort to sort the elements of the stack (make function called Bubble_sort_Stack).*/

#include <iostream>
#include <conio.h>
using namespace std;

void displaystack();
void stack();
void bubblesort();
void selectionsort();
void insertionsort();

struct node
{
	int number;
	node*next;
	node*prev;
};
node*top = nullptr;
node*bottom = nullptr;
node*current = nullptr;
node*i = new node;
node*j = new node;

int temp;

int main()
{
	system("color F0");
	stack();
	cout << "Stack: \n";
	displaystack();

	char button;
	cout << "b. Bubble sort\n";
	cout << "s. Selection sort\n";
	cout << "i. Insertion sort\n\n";
	button = _getch();

	switch (button)
	{
	case'b':
		cout << "Bubble sort: \n";
		bubblesort();
		displaystack();
		break;

	case's':
		cout << "Selection sort: \n";
		selectionsort();
		displaystack();
		break;

	case'i':
		cout << "Insertion sort: \n";
		insertionsort();
		displaystack();
		break;

	default:
		cout << "Enter one of the shown buttons!\n\n";
		break;
	}
	return 0;
}

void stack()
{
	int numbers[5] = { 300,100,500,200,400 };

	for (int k = 0; k < 5; k++)
	{
		current = new node;
		current->number = numbers[k];
		

		if (top == nullptr)
		{
			top = current;
			bottom = current;
			current->next = nullptr;
			
		}
		else
		{
			top->prev = current;
			current->next = top;
			top = current;
		}
	}
}
void displaystack()
{
	current = top;
	while (current != nullptr)
	{
		cout << current->number << endl;
		current = current->next;
	}
	cout << endl;
}
void bubblesort()
{
	for (i = top; i != bottom; i = i->next)
	{
		for (j = top; j != bottom; j = j->next)
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
	for (i = top; i != NULL; i = i->next)
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
	for (i = top->next; i != NULL; i = i->next)
	{
		for (j = i; j != top; j = j->prev)
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