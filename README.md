
Exercise Name: EX1 – Hash Tables.

Files:

GenericHashTable.c :	 C file implements the all functions located in the h file.
GenericHashTable.h :	 Header file/the interface.

Remarks: 

This program implements an hash table, while each of the following actions done on o(d) while d is a constant:
insert, delete and search element.
There are 3 main functions in the program that do that actions, the function are:
add (insert) - this function gets an integer or a string, and insert it to the hash table.
removeObj (delete) - this function remove element from the table.
search - this funciton find the index of some specific object in the table.
The remain functions are helper or private functions that help to the main function to do the work.
The program handle collisions by extend the table length while needing.

there are two addiotional function:
intHashFun - gets an integer and return its hash index in the table.
strHashFun - gets a string and return its hash index in the table.

I wrote one private function:
-doubleTheTableSize : gets a table and return it with double length and the all data placed in the index*2 from the old table.


