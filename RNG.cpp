#include <random>
#include <vector>
#include <iostream>
#include <time.h>
#include "RNG.h"
using namespace std;

void Generate_Random(int start, int end)
{
	//random_device seed;
    //mt19937 generator(seed()); // random_device seed not working with MinGW gcc compiler!
	mt19937 generator(time(NULL));
	//mt19937 generator(random_device{}()); written without "random_device seed;"
    uniform_int_distribution<int> random(start,end);
	
	for (int i=start; i<=end; i++)
    cout << random(generator) << " ";
}
