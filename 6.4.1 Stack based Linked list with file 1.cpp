/*Write C++ program to read the following list of numbers from a file (34, 20,311,99) then push them in stack-based linked list, after that print the odd numbers of them on the screen.*/

#include <iostream>
#include <fstream>
using namespace std;

#define Size 5
int array_of_numbers[Size];

void read_from_file();
void display_odd();



int main()
{
	printf("Stack contains: \n");
	read_from_file();

	cout << "Odd values: \n";
	display_odd();


    return 0;
}

void read_from_file()
{
	fstream in("Stack.txt");

	for (int i = 0; i < 5; i++)
	{
		in >> array_of_numbers[i];  //Reading contents of the file.
	}
	in.close();
	

	for (int i = Size; i >= 1; i--)
		cout << array_of_numbers[i-1] << endl; //Displaying the contents in the form of Stack.
	cout<< endl;
}

void display_odd()
{
	for (int i = Size; i >= 1; i--)
	{
		if (array_of_numbers[i - 1] % 2 != 0)
			cout << array_of_numbers[i - 1]<< endl;
	}
	cout << endl;
}

