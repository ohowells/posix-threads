#include <iostream>
#include <pthread.h>
#include <random>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define COL 15000
#define ROW 15000

static float random_set      [ROW][COL];
static float edist_result_set[ROW][COL];
static float angle_result_set[ROW][COL];

// **number of threads MUST be even!! (2, 4, 6, 8 ect.)**
static const int number_of_threads = 4;
static const int number_of_rows    = ROW/number_of_threads;

// struct is passed to each thread, giving each their own
// start and end rows to process.
struct RowsToProcess { int end, start; };

static void FillArray(void)
{
	std::default_random_engine rand;
	std::uniform_int_distribution<> dis(1, 20);

	for (auto i = 0; i < ROW; i++)
	{
		for (auto j = 0; j < COL; j++)
			random_set[i][j] = dis(rand);
	}
}

// setup load bar, if bar is not full continue, else return.
// start = number of iterations, end = rows being processed.
//
// example output: 99% |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |
//
// code written by: Ross Hemsley
// code found here: https://www.ross.click/2011/02/creating-a-progress-bar-in-c-or-any-other-console-app/
static void LoadBar(int start, int end, int width = 70)
{
    if ((start != end) && (start % (end / 100 + 1) != 0)) return;

    float fill   = start / (float)end;
    int progress = fill * width;

    std::cout << "\t" << (int)(fill * 100) << "% |";
    for (int i = 0; i < progress; i++)     std::cout << ">";
    for (int i = progress; i < width; i++) std::cout << " ";
    std::cout << "|\r" << std::flush;
}

void* ProcessRowsThread(void* param)
{
    RowsToProcess *next = (RowsToProcess *)param;
    int start_row       = next->start;
	int end_row         = next->end;

	for (auto i = start_row; i < end_row; i++)
	{
		int temp_j = 0;
		for (auto j = start_row; j < COL - 1; j++)
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
		LoadBar(i, end_row);
	}
}


int main(void)
{
    int start_row = 0;
	int end_row   = number_of_rows;
    timespec start, finish;

	pthread_t n_threads[number_of_threads];
	RowsToProcess struct_data[number_of_threads];

	FillArray();
    // CLOCK_MONOTONIC represents the absolute elapsed wall-clock time
    // since some arbitrary, fixed point in the past e.g. start.
    clock_gettime(CLOCK_MONOTONIC, &start);

	for (auto i = 0; i < number_of_threads; i++)
	{
	    struct_data[i].start = start_row;
	    struct_data[i].end   = end_row;

		pthread_create(&n_threads[i], NULL, ProcessRowsThread, &struct_data[i]);

		// each subsequent thread made will start where the last left off.
		start_row += number_of_rows;
		end_row   += number_of_rows;
	}

	for (auto i = 0; i < number_of_threads; i++)
	    pthread_join(n_threads[i], NULL);

    clock_gettime(CLOCK_MONOTONIC, &finish);

    // .tv_sec returns the elasped time in seconds
    short time_in_thread = (finish.tv_sec - start.tv_sec);

    std::cout << "\n\nNumber of rows: " << ROW
              << "\nNumber of colums: " << COL;

    std::cout << "\n\nNumber of threads: " << number_of_threads
              << "\nRows per thread: " << number_of_rows
              << "\nTime taken: " << time_in_thread << " seconds\n\n";

	pthread_exit(NULL);
	return 0;
}
