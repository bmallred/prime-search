Primes: a search for
--------------------


Okay I was playing with some silly ideas and looking over my many FizzBuzz programs when I realized they were the beginnings of prime searches.

This is in a very rough state,  I am looking to break this apart to use with threads and MPI now that I have aprox 3/4's of the numbers removed with the modules and SQRT tests. 

**
Next step?
Using the linked list, use the list with a group of threads where each thread handles a node (or integer) to run modulus against that number from a smaller and smaller list.

Because we only want so many threads running on one heap, use of MPI to create more heaps than will be required as the search grows. As the search grows so will the length of time the threads are working on each node.

The program is very simple:
 - it pulls a start:end point for search of primes
 - moduls is used at 2,3,5 rotations
 - a list is built
 - sqrt is ran against list 
 - output of list (unfinished list)


**
TODO:
 - major makefile clean
 - adjust linklist to make smaller
 - build threads 
 - seperate list and work layered division

Compiling
---------

```
make
```

Execute
-------

To execute the program you can use the following arguments:
 - **-h**: outputs the help text
 - **-v**: outputs a arbitrary version number
 - **-s**: starting number
 - **-e**: ending number

Example:
```
./prime-search -s 0 -e 100


Expected output: a short version
 7 	 11 	 13 	 17 	 19 	 23 	 29 	 31 	 37 	 41 
```


