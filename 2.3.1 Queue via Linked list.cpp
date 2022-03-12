/* 2.3.1 Write C++ program to implement the basic operations of Queue as we discussed above, through creating menu to handle different operations and if the user wants to quit s/he must press escape button from the keyboard */

#include <iostream>
#include <conio.h>
using namespace std;

struct node {
	int data;
	node*next;
};

node*front = NULL;
node*rear = 0;
node*current = NULL;

void enqueue(int);
void dequeue();
void display_front();
void display_queue();
void dequeueALL();

int main()
{
	int value=0;
	char key=0;

	printf("**Basic Queue of numbers**\n");
	printf("-----------------------------\n");

	while (key != 27)
	{
		cout << "a. to add a value\n";
		cout << "s. to dismiss the first value\n";
		cout << "f. to display the first value\n";
		cout << "g. display the queue\n";
		cout << "d. dismiss the whole queue\n";
		cout << "Press ESC to exit\n\n";
		key = _getch();

		switch (key)
		{
		case 'a':
			cout << "Enter a value: "; cin >> value;
			enqueue(value);
			cout << "Done!\n\n";
			break;

		case 's':
			dequeue();
			break;

		case 'f':
			display_front();
			break;

		case'g':
			display_queue();
			break;

		case 'd':
			dequeueALL();
			break;

		case 27:
			break;

		default:
			cout << "Please press one of the displayed buttons!\n\n";
			break;
		}
	}


    return 0;
}

void enqueue(int num)
{
	current = new node;
	current->data = num;
	current->next = NULL;

	if (front == NULL && rear == NULL)
	{
		front = rear = current;
	}
	else {
		rear->next = current;
		rear = current;
	}
}

void dequeue()
{
	if (front == NULL && rear == NULL)
		cout << "Queue is empty !\n\n";
	else if (front == rear)
	{
		front = rear = NULL;
		cout << "This value is dismissed and the queue has become empty!\n\n";
	}
	
	else
	{
		current = front;
		front = front->next;
		delete current;
		cout << "First value is dismissed!\n\n";
	}
}

void display_front()
{
	if (front == NULL&& rear == NULL)
		cout << "Queue is empty!\n\n";
	else
	{
		cout << "First value is " << front->data << "\n\n";
	}
}

void display_queue()
{
	if (front == NULL&& rear == NULL)
		cout << "Queue is empty!\n\n";
	else
	{
		cout << "Queue contains: \n";
		current = front;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}	
	}
	cout << endl;
}

void dequeueALL()
{
	if (front == NULL&& rear == NULL)
		cout << "Queue is empty!\n\n";
	else
	{
		while (current != NULL)
		{
			current = front;
			front = front->next;
			delete current;
		}
		rear = front = NULL;
		cout << "Queue is dismissed!\n\n";
	}
}

		












