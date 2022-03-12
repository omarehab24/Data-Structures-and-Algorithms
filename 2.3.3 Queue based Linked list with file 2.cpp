/* 2.3.3 Write C++ program to read the following list of numbers from a file (4, 13, 8, 7, 25,74) then insert them in Queue based linked list, after that print the even numbers of them in a file. */

#include <iostream>
#include <fstream>
using namespace std;

void read_from_file();
void save_even_in_file();

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

	save_even_in_file();
	cout << "Even values has been saved in a file.\n\n";

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

void save_even_in_file()
{
	ofstream out("EvenValues.txt");
	cout << "Even values: \n";

	current = front;
	while (current != NULL)
	{
		if (current->value % 2 == 0)
		{
			cout << current->value << endl;
			out << current->value << endl;
		}
		current = current->next;
	}
	out.close();

	cout << endl;

}

