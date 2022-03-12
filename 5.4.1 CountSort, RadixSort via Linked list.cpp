/* Write C++ program to implement linked list to insert these elements (40,5,33,20,180)
then:
• Use Count sort to sort the elements of the linked list (make function called Count_sort_Link).
• Use Radix sort to sort the elements of the linked list (make function called Radix_sort_Link).
• Use Merge sort to sort the elements of the linked list (make function called Merge_sort_Link).*/

// Note: Merge sort isn't implemented yet!

#include <iostream>
#include <conio.h>
using namespace std;

void linkedlist();
void display();
void max();
void countsort();
void radixsort();
void mergesort();

struct node
{
	int data;
	node*next;
	node*prev;
};
node*head = nullptr;
node*tail = nullptr;
node*current = nullptr;
node *i = nullptr;
node *j = nullptr;
node* l = nullptr;
node* mid = head;

int k;

int main()
{
	cout << "LinkedList: \n";
	linkedlist();
	display();
	max();

	char button = 0;

	while (button != 'c' && button != 'r' && button != 'm'& button != 27)
	{
		cout << "c. Count sort\n";
		cout << "r. Radix sort\n";
		cout << "m. Merge sort\n";
		cout << "Press ESC to exit\n\n";

		button = _getch();

		switch (button)
		{
		case'c':
			cout << "Count sort: \n";
			countsort();
			break;

		case'r':
			cout << "Radix sort: \n";
			radixsort();
			display();
			break;

		case'm':
			cout << "Merge sort: \n";
			mergesort();
			display();
			break;

		case 27:
			break;

		default:
			cout << "Hit one of the displayed buttons!\n\n";
			break;
		}
	}
	
    return 0;
}


void linkedlist()
{
	int array[5] = { 40,5,33,20,180 };

	for (int j = 0; j < 5; j++)
	{
		current = new node;
		current->data = array[j];
		current->next = nullptr;

		if (head == nullptr)
		{
			head = current;
			tail = current;
			head->prev = nullptr;
		}
		else
		{
			tail->next = current;
			current->prev = tail;
			tail = current;
		}
	}
}

void display()
{
	current = head;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;
}

void max() //Getting the max value from the linked list
{
	current = head;
	while (current != nullptr)
	{
		if (current->data > k)
		{
			k = current->data;
		}
		current = current->next;
	}
}

void countsort()
{
	int *index = new int[k]; int output[5];

	for (int i = 0; i <= k; i++)
		index[i] = 0;

	for (current = head; current != NULL; current = current->next)
		++index[current->data];

	for (int i = 1; i <= k; i++)
		index[i] += index[i - 1];

	for (current = tail; current != NULL; current = current->prev)
		output[--index[current->data]] = current->data;
	
	current = head;
	for (int j = 0; j < 5; j++)
	{
			current->data = output[j];
			cout << current->data << endl;
			current = current->next;
	}
	cout << endl;
}

void radixsort()
{
	int index[10];
	int output[5];

	for (int pos = 1; (k / pos) > 0; pos *= 10)
	{
		for (int i = 0; i <= 9; i++)
			index[i] = 0;

		for (current = head; current != NULL; current = current->next)
			index[(current->data / pos) % 10]++;

		for (int i = 1; i <= 9; i++)
			index[i] += index[i - 1];

		for (current = tail; current != NULL; current = current->prev)
			output[--index[(current->data / pos) % 10]] = current->data;

		current = head;
		for (int j = 0; j < 5; j++)
		{
			current->data = output[j];
			current = current->next;
		}
	}
}

void mergesort()
{
	for (i = head; i != tail; i = i->next)
	{
		for (j = head; j != tail; j = j->next)
		{
			if (j->data > j->next->data)
			{
				int temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}

}
