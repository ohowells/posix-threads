# Posix Threads

The three pieces of code above solve the following problem.

Consider a 2D data array whose contents needs to be processed.  
The array consists of values representing the height in a terrain at that point.  
Create two new arrays to hold the results of calculations.  
Result array one is to hold the Euclidean distance between each point and the
next point in the row.  
Result array two is to hold the angle of the slope between the point and its
neighbour calculated using arcsin.


- Set up the first array and write a sequential program that 
accesses the data array and populates the result arrays.

- A second program that it is still sequential but accesses
the data array by a series of calls to a single function. Each
call to that function will process a number of rows of the
array as defined by a parameter passed to the function.

- A third version of the program that will allow the processing
to be carried out in one or more threads. Each thread should
access a different set of rows of the array as in 2.
above so that locking etc. is not an issue.

To run type the commands:

>make    
>./a.out
