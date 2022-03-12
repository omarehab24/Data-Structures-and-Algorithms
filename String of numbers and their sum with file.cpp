#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	
	fstream in;
	string x;
	in.open("student.txt", ios::in);
	in >> x;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == ',')
			x[i] = ' ';

		cout << x[i] << " ";
	}
	stringstream ss(x);
	int array[4];
	int sum = 0;

	for (int i = 0; i < x.length() && ss.good(); i++)
	{
		ss >> array[i];
		sum += array[i];
	}
	in.close();

	cout << "\t sum = " << sum << endl;

	ofstream out("student.txt", ios::app);
	out <<"\t sum = "<< sum;
	in.close();


	return 0;
}


