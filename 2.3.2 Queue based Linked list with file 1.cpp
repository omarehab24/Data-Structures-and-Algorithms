/*2.3.2 Write C++ program to read the following list of numbers from a file (4, 13, 8, 7, 25,74) then insert them in Queue based linked list, after that print the odd numbers of them on the Console screen.*/

#include <iostream>
#include <fstream>
using namespace std;

void read_from_file();
void display_odd();

struct node {
	int value;
	node*next;
};

node*front = 0;
node*rear = 0;
node*current = 0;

int main()
{
	cout << "The file contains: \n";
	read_from_file();
	cout << endl;

	
	display_odd();

    return 0;
}

void read_from_file()
{
	ifstream in;
	in.open("Queue.txt");

	while (!in.eof())
	{
		current = new node;
		in >> current->value;
		current->next = NULL;
		
		if (front == NULL && rear == NULL)
		{
			front = rear = current;
		}
		else {
			rear->next = current;
			rear = current;
		}
		cout << current->value << endl;
	}
	
	in.close();	
}

void display_odd()
{
	current = front;
	cout << "Odd values: \n";
	while (current != NULL)
	{
		if (current->value % 2 != 0)
		{
			cout << current->value << endl;

		}
		current = current->next;
	}
	cout << endl;
}





