/*1 Write C++ program to read the following list of numbers from a file (35, 26,201,74) then push them in stack-based linked list, after that print the even numbers of them on the screen.*/

#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int value;
	node*next;
};

node*top = nullptr;
node*current = nullptr;

void read_from_file();
void display_even();



int main()
{
	cout << "Stack contains: \n";
	read_from_file();
	cout << endl;

	cout << "Even values: \n";
	display_even();
	cout << endl;

    return 0;
}

void read_from_file()
{
	ifstream input;
	input.open("Stack.txt");

	while (!input.eof())
	{
		current = new node();
		input >> current->value;
		current->next = top;
		top = current;
	}

	current = top;
	while (current != NULL)
	{
		cout << current->value << endl;
		current = current->next;
	}
	input.close();

	
}

void display_even()
{
	current = top;
	while (current != NULL)
	{
		if (current->value % 2 == 0)
		{
			cout << current->value << endl;
		}
		current = current->next;
	}

}

