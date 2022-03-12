//Implementation file

#include <ctime>

double elapsed;
clock_t start_time;
bool running = false;

void start_timer()
{
	if (!running) 	
	{
		running = true;
		start_time = clock();
	}		
	
}

void stop_timer()
{
	if (running)
		{
			clock_t stop_time = clock();
			running = false;
			elapsed += static_cast<double>((stop_time - start_time))/CLOCKS_PER_SEC;
	} 
	
	
}

double elapsed_time()
{
	if (running)
	{
		clock_t current_time = clock();
		return elapsed + static_cast<double>((current_time - start_time));
	}
	else 
		return elapsed;
}

void reset_timer()
{
	elapsed = 0.0;
	running = false;
}