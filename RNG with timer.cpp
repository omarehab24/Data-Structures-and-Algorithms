#include <iostream>
#include "timer.h"
#include "RNG.h"
using namespace std;

int main()
{
	start_timer();
	
	cout << " Inputs: ";
	 int x,y;
	cin >> x >> y;
	
	cout << "\n";
	
	Generate_Random(x,y);
	
	stop_timer();
	
	cout << "\n\n";
	cout << elapsed_time() << " seconds" << '\n';
}