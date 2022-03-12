

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;


void insert_to_head();
void insert_to_tail();
void print_list();
void delete_node(string);
void delete_list();

struct student
{
	int age;
	float gpa;
	string name;
};

struct node
{
	student data;
	node* next;
};

node*current = NULL;
node*head = NULL;
node*tail = nullptr;
node*temp = NULL;
node*stu = NULL;

int main()
{
	student input;
	string name;
	int button = 0;

	while (button != 27)
	{
		cout << "1. Insert a node to the head of list\n";
		cout << "2. Insert a node to the end of list\n";
		cout << "3. View the list \n";
		cout << "4. Delete a node in the list \n";
		cout << "5. Delete the whole list \n";
		cout << "Press ESC to exit \n\n";

		button = _getch();

		switch (button)
		{
		case '1':
			insert_to_head();
			cout << "Done!\n\n";
			break;

		case '2':
			insert_to_tail();
			cout << "Done!\n\n";
			break;

		case '3':
			print_list();
			break;

		case '4':
			cout << "Delete a student's info by typing his name: ";  cin >> name;
			delete_node(name);
			break;

		case '5':
			delete_list();
			break;

		case 27:
			break;

		default:
			cout << "Enter one of the displayed buttons!\n\n";
			break;
		}

	}

	return 0;
}

void insert_to_head()
{
	stu = new node;
	cout << "Enter the student's name: "; cin >> stu->data.name;//getline(cin, stu->data.name); cin.clear(); cin.ignore();
	cout << "Enter the student's age: "; cin >> stu->data.age;
	cout << "Enter the student's gpa: "; cin >> stu->data.gpa;
	cout << endl;
	stu->next = NULL;

	if (head == NULL)
	{
		head = stu;
		tail = stu;
	}

	else
	{
		stu->next = head;
		head = stu;
	}
}
void insert_to_tail()
{
	stu = new node;
	cout << "Enter the student's name: "; cin >> stu->data.name;
	cout << "Enter the student's age: "; cin >> stu->data.age;
	cout << "Enter the student's gpa: "; cin >> stu->data.gpa;
	cout << endl;
	stu->next = NULL;

	if (head == NULL)
	{
		head = stu;
		tail = stu;
	}
	else
	{
		tail->next = stu;
		tail = stu;
	}
}
void print_list()
{
	if (head == NULL)
	{
		cout << "The list is empty! \n\n";
		return;
	}

	cout << "Student(s) info: \n\n";

	current = stu = head;
	cout << "Student Name\t" << "Student Age\t"<< "Student GPA\t\n";
	while (current != NULL)
	{
		cout << current->data.name << "\t\t";
		cout << current->data.age << "\t\t";
		cout << current->data.gpa <<"\n\n";
		//cout << endl;
		current = current->next;
	}
}
void delete_node(string input)
{
	if (head == NULL)
	{
		cout << "The list is empty! \n\n";
		return;
	}

	temp = current = head = stu;
	if (current->data.name == input)
	{
		head = head->next;
		delete current;
		cout << "Deleted Successfully! \n\n";
		return;
	}

	while (current != NULL && current->data.name != input)
	{
		temp = current;
		current = current->next;
	}

	if (current == NULL)
	{
		cout << "Student wasn't found! \n\n";
		return;
	}

	temp->next = current->next;
	delete current;
	cout << "Deleted Successfully! \n\n";
}

void delete_list()
{
	if (head == NULL)
	{
		cout << "The list is empty! \n\n";
		return;
	}

	current = head = stu;
	while (current != NULL)
	{
		head = head->next;
		delete current;
		current = head;
	}
	head = NULL;
	tail = NULL;
	cout << "The list is deleted successfully! \n\n";
}
