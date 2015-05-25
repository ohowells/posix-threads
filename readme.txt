Some code showing implementation of POSIX threads under linux 

Set up the first array and write a sequential program that accesses 
the data array and populates the result arrays. 

A second program that it is still sequential but accesses 
the data array by a series of calls to a single function. Each 
call to that function will process a number of rows of the 
array as defined by a parameter passed to the function.

A third version of the program that will allow the processing 
to be carried out in one or more threads. Each thread should 
access a different set of rows of the array as in 2. 
above so that locking etc. is not an issue.
