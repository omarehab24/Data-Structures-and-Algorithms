/*Write a C++ Program that read the personal data for 3 employees from the console window as follows ID, Name, Mobile number, and Job title, using linked list then save these data in a file.*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct employee
{
	string name;
	string job;
	int id;
	long mobile;
};

struct node
{
	employee data;
	node*next;
};

node*head = NULL;
node*tail = NULL;
node*current = NULL;

void employees()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Employee no." << i + 1 << "'s data\n";
		node*Employee = new node;
		cout << "Enter employee's name: ";
		cin >> Employee->data.name;
		cout << "Enter employee's job: ";
		cin >> Employee->data.job;
		cout << "Enter employee's id: ";
		cin >> Employee->data.id;
		cout << "Enter employee's mobile: ";
		cin >> Employee->data.mobile;
		Employee->next = NULL;
		cout << endl;

		current = Employee;
		if (head != NULL)
		{
			tail->next = current;
			tail = current;
		}
		else
		{
			head = current;
			tail = current;
		}
	}
	cout << "*****==*****==*****==*****==*****==*****\n";
	current = head;
	while (current != NULL)
	{
		cout << "Employee's name: " << current->data.name << endl;
		cout << "Employee's job: " << current->data.job << endl;
		cout << "Employee's id: " << current->data.id << endl;
		cout << "Employee's mobile: " << current->data.mobile << endl;
		current = current->next;	
		cout << endl;
	}

}

void savetofile()
{
	ofstream out("File.txt");
	current = head;
	out << "Employees data\n" << "----------------\n";
	while (current != NULL)
	{
		out << "Employee's name: " << current->data.name << endl;
		out << "Employee's job: " << current->data.job << endl;
		out << "Employee's id: " << current->data.id << endl;
		out << "Employee's mobile: " << current->data.mobile << endl;
		current = current->next;
		out << endl << endl;
	}
	out.close();
}


int main()
{
	employees();
	savetofile();

    return 0;
}

