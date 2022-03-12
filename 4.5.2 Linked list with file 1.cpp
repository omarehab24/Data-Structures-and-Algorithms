/*Write C++ program to read the following list of numbers from a file (2,1,3,4,5,6,7,8,12,51,98,11) then insert them in a linked list, after that print the even numbers of them on the screen.*/

#include <iostream>
#include <fstream>
using namespace std;

void readfile();
void printeven();

struct node
{
	int numbers;
	node*next;
};

node*head = nullptr;
node*tail = nullptr;
node*current = nullptr;

int main()
{
	printf("linked list contains: \n");
	readfile();

	cout << "Even values: \n";
	printeven();

    return 0;
}



void readfile()
{

	ifstream in("file.txt");
	while (!in.eof())
	{
		current = new node;
		in >> current->numbers;
		current->next = nullptr;

		if (head != nullptr)
		{
			tail->next = current;
			tail = current;
		}
		else
		{
			head = current;
			tail = current;
		}
		cout << current->numbers << endl;
	}
	in.close();
	cout << endl;
}

void printeven()
{
	current = head;
	while (current != nullptr)
	{
		if (current->numbers % 2 == 0)
			cout << current->numbers << endl;
		
		current = current->next;
	}
	cout << endl;
}