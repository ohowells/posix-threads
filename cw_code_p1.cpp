#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define COL 5000
#define ROW 5000

static float random_set      [ROW][COL];
static float edist_result_set[ROW][COL];
static float angle_result_set[ROW][COL];

int main(void)
{   
    int start_row = 0; 
    int end_row   = ROW;
    timespec start, finish;
    
    // CLOCK_MONOTONIC represents the absolute elapsed wall-clock time 
    // since some arbitrary, fixed point in the past e.g start.
    clock_gettime(CLOCK_MONOTONIC, &start); 
    
    // fill array
	srand((float)time(NULL));
	for (auto i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			random_set[i][j] = (rand() % 20 + 1);
	}
    std::cout << std::endl;
    
    // process rows of the array 
	for (int i = start_row; i < end_row; i++)
	{
		int temp_j = 0;
		for (int j = start_row; j < COL - 1; j++)
		{
			edist_result_set[i][j] = sqrt(
				                          pow(random_set[i][j], 2.0) +
				                          pow(random_set[i][++temp_j], 2.0)
				                          );
		
			angle_result_set[i][j] = asin(
				                          random_set[i][j] /
				                          edist_result_set[i][j]
				                          ) * 180 / M_PI;
		}
		std::cout << "\r\t" << "Calculations completed: " 
		          << 100 * (i + 1) / end_row << "% " << std::flush;
	}	
	
    clock_gettime(CLOCK_MONOTONIC, &finish);
    float time = (finish.tv_sec - start.tv_sec);
    
    std::cout << "\n\nNumber of rows: " << ROW 
              << "\nNumber of colums: " << COL
              << "\nTime taken: " << time << " seconds\n\n";
    
	return 0;
}
