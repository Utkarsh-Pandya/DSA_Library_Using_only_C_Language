# DSA_Library_Using_only_C_Language

This is a DSA library containing various sorting algorithms, stack, queue etc., written in C programing Language.
And all the functions/algorithms are *generic*, that is if possible you can apply this library on any datatype.

This Project contains 3 Folders:

--> *Include* : It contains all the header files, for the library.

--> *Lib* : It contains the main library file.

--> *Src* : It contains all the source file (i.e. Code) and their object files for all header files.


This Library includes:

-> 20 Sorting Algorithms

-> Stack

-> Queue

-> Linked List

-> And Various utility functions such as merge, number_of_digits_in_an_integer etc.


You can see the syntax for each function in the include section.
For each function you have to pass two integers at the end in each function. The first integer will return if the program is executed successfully or not.
And if it is not executed successfully than the second integer will return you a error number, whilh will give you the error/problem for the unsuccessful/failed run of the program. You can check the error from *myerr.h* file in the include section.


To use this library you just need to download this three folders on your desktop and you are good to go.
To run a C-file (let it be filename.c) using mylib library, write the given below statement on your command prompt:
*gcc filename.c -o filename.exe -I ..\include -L..\lib -lmylib*
After -I and -L you need to provide the path to the include and lib folder respectively.


Thank You for your time


-by
Utkarsh Pandya
