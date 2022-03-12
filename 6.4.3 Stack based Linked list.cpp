/*Write C++ program to implement the basic operations of Stack as we discussed above, through creating menu to handle different operations and if the user wants to quit s/he must press escape button from the keyboard */

#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int data;
	node*next;
};

node*top = nullptr;
node*current = nullptr;

void push(int);
void pop();
void display();
void pop_all();


int main()
{
	cout << "**Basic Stack of numbers**\n" << "----------------------------------\n";
	int key=0;
	int value=0;

	while (key != 27)
	{
		cout << "a. to add a number to the stack\n";
		cout << "r. to remove the added number\n";
		cout << "f. to display the stack\n";
		cout << "d. to evacuate the stack\n";
		printf("Press ESC to exit\n\n");
		key = _getch();

		switch (key)
		{
		case'a':
			printf("Enter a number: "); cin >> value;
			push(value);
			printf("Done!\n\n");
			break;

		case'r':
			pop();
			break;

		case'f':
			display();
			break;

		case'd':
			pop_all();
			break;
		case 27:
			break;

		default:
			cout << "Please hit one of the displayed buttons!\n";
				break;
		}
	}

    return 0;
}


bool empty()
{
	if (top == nullptr)
		return true;
	else
		return false;
}

void push(int num)
{
	current = new node;
	current->data = num;

	if (empty())
	{
		current->next = top;
		top = current;
	}
	else
	{
		current->next = top;
		top = current;
	}
	
}

void pop()
{
	if (empty())
	{
		cout << "Stack is empty!\n\n";
		return;
	}

	if(!empty())
	{
		current = top;
		top = top->next;
		delete current;
		printf("Done!\n\n");
	}
}

void display()
{
	if (empty())
	{
		cout << "Stack is empty!\n\n";
		return;
	}
		
	current = top;
	cout << "Stack contains: \n";
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;

}

void pop_all()
{
	if (top != NULL)
	{
		current = top;
		while (current != NULL)
		{
			top = top->next;
			delete current;
			current = top;
		}
		printf("Done!\n\n");
	}
	else
		cout << "Stack is empty!\n\n";
}
