all: ex1_main.c 
	 	gcc ex1_main.c GenericHashTable.c -Wvla -Wall -o ex1_main
all-GDB: ex1_main.c
	 	gcc -g ex1_main.c GenericHashTable.c -Wvla -Wall -o ex1_main

		 