#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct StudentData
{
	int studentID;
	string name;
	float gpa;
	int age;
}stu;

void writeToFile(string);

int main()
{
	string filename = "student.txt";
	writeToFile(filename);
}

void writeToFile(string filename)
{
	ofstream myfile;
	myfile.open(filename);

	myfile << " ID \t" << " Name \t" << " GPA \t" << " Age \t" << endl;
	cout << "Enter information of student " << endl;

	cout << "enter ID :";
	cin >> stu.studentID;
	myfile << " " << stu.studentID << " \t";

	cin.ignore(); //to clear buffer

	cout << "enter name :";
	getline(cin, stu.name);
	myfile << " " << stu.name << " \t";

	cout << "enter GPA :";
	cin >> stu.gpa;
	myfile << " " << stu.gpa << " \t";

	cout << "enter age :";
	cin >> stu.age;
	myfile << " " << stu.age << " \t";

	myfile.close();
}
