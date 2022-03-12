/*Write C++ program that gives two linked lists representing non-negative integers. Each of their nodes contain a single digit. Add the two numbers and return it as a linked list.*/

#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int value;
	node*link;
};
node*first = nullptr;
node*last = nullptr;
node*current = nullptr;


struct node1
{
	int value1;
	node1*link1;
};
node1*first1 = nullptr;
node1*last1 = nullptr;
node1*current1 = nullptr;

void linkedlist1(int);
void linkedlist2(int);
void linkedlist3();
void display1();
void display2();


int main()
{
	char button = 0;
	int x = 0;
	while (button != 27)
	{
		cout << "q. add a number to linked list 1 \n";
		cout << "w. add a number to linked list 2 \n";
		cout << "r. display linked list 1 \n";
		cout << "t. display linked list 2 \n";
		cout << "a. add linked list 1 to linked list 2 \n";
		cout << "Press ESC to exit\n\n";

		button = _getch();

		switch (button)
		{
		case'q':
			cout << "Enter a number: "; cin >> x;
			if ( x<0 || x>10 )
				cout << "Enter a single non-negative digit!\n\n";
			else
			{
				linkedlist1(x);
				cout << "Done!\n\n";
			}
			break;

		case'w':
			cout << "Enter a number: "; cin >> x;
			if (x < 0 || x>10)
				cout << "Enter a single non-negative digit!\n\n";
			else
			{
				linkedlist2(x);
				cout << "Done!\n\n";
			}
			break;

		case'r':
			display1();
			break;

		case't':
			display2();
			break;

		case'a':
			linkedlist3();
			break;

		case 27:
			break;

		default:
			cout << "Enter one of the shown buttons!\n\n";
			break;
		}

	}

    return 0;
}


void linkedlist1(int y)
{
	current = new node;
	current->value = y;
	current->link = nullptr;

	if (first== nullptr)
	{
		first = current;
		last = current;
	}
	else
	{
		last->link = current;
		last = current;
	}
}

void display1()
{
	if (first == nullptr)
		cout << "list is empty!\n\n";
	else
	{
		cout << "List1 contains: \n" << "{ ";
		current = first;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->link;
		}
		cout << "}\n\n";
	}
}


void linkedlist2(int z)
{
	current1 = new node1;
	current1->value1 = z;
	current1->link1 = nullptr;

	if (first1 == nullptr)
	{
		first1 = current1;
		last1 = current1;
	}
	else
	{
		last1->link1 = current1;
		last1 = current1;
	}
}

void display2()
{
	if (first1 == nullptr)
		cout << "list is empty!\n\n";
	else
	{
		cout << "List2 contains: \n" << "{ ";
		current1 = first1;
		while (current1 != nullptr)
		{
			cout << current1->value1 << " ";
			current1 = current1->link1;
		}
		cout << "}\n\n";
	}
}


void linkedlist3()
{
	struct node2 {

		int value2;
		node2*link2;
	};
	node2*current2 = nullptr;
	node2*first2 = nullptr;


	if (first1 == nullptr && first == nullptr)
	{
		cout << "Nothing to add!\n\n";
		return;
	}

	current = first;
	current1 = first1;


	cout << "Sum of list1 and list2 is: \n" << "{ ";
	while (current != nullptr && current1 != nullptr)
	{
		current2 = new node2;
		current2->value2 = current->value + current1->value1;
		cout << current2->value2 << " ";
		current = current->link;
		current1 = current1->link1;
		current2 = current2->link2;
	}
	cout << "}\n\n";
}