#include <stdio.h>
#include <string.h>
#include "GenericHashTable.h"


int main()
{
    Table* t = createTable(4,STR_TYPE,5);
    
    char* x0 = "a"; 
    char* x1 = "b"; 
    char* x2 = "c"; 
    char* x3 = "d"; 
    char* x4 = "e"; 
    char* x5 = "f"; 
    char* x6 = "ab"; 
    char* x7 = "bcd"; 
    char* x8 = "randi"; 
    char* x9 = "harel"; 
    char* x10 = "gulag"; 

    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x0));
    printf("index %d\n", add(t,x1));
    printf("index %d\n", add(t,x9));
    printf("index %d\n", add(t,x8));
    printf("index %d\n", add(t,x5));
    printf("index %d\n", add(t,x10));


    printf("index %d\n", removeObj(t,x5));
    printf("index %d\n", removeObj(t,x9));
    printf("index %d\n", removeObj(t,x10));

    char* try= "f";
    Object* toPrint = search(t,try);

    if(toPrint!=NULL)
    {
      char* hop=(char*)toPrint->data;
      printf("--%s--\n",hop);
    }
    else{
        printf("asdsadasdas\n");
    }

    printTable(t);
    freeTable(t);

    return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include "GenericHashTable.h"

// #define F 			1 //free t1, t2, t3 --15 points

// // check serach method
// #define Test1 			1 // 5 points S1
// #define Test2 			1 // 5 points S2
// #define Test3 			1 // 5 points S3
// #define Test4 			1 // 5 points S4
// #define Test5 			1 // 5 points S5
// #define Test6 			1 // 5 points S6
// #define Test7 			1 // 5 points S7

// // check remove method
// #define Test8 			1 // 5 points R1
// #define Test9 			1 // 5 points R2
// #define Test10 			1 // 5 points R3
// #define Test12 			1 // 5 points R4
// #define Test11 			1 // 5 points R5
// #define Test13 			1 // 5 points R6
// #define Test14 			1 // 5 points R7

// #define CHECK_INT 	1 // 5 points (create int table)
// #define CHECK_STRING 1 // 5 points (create string table)
// #define FREE_TABLE 	1 // 10 points if all heap blocks were freed
// int count_test=0;
// 	//check all classes if they can get null data
//     //check method 1
//     //check method 2
//     //check method n
//     // ----------------------------------------------
//     // Input Validation
// int main()
//     {
// 	Table* t1 = createTable(-1, 1, 1);
// 	printf("-------------------------------------------------------\n");
// 	printf("***Input Validation***\n");
// 	if(t1 != NULL)
// 	{
// 		printf("Didnt check size\n");
// 		if(F)
// 			freeTable(t1);
// 	}
//     else
//     {
//         printf("Valid1-size checked +5\n");
//         count_test+=5;
//     }
// 	Table* t2 = createTable(1, -1, 1);
// 	if(t2 != NULL)
// 	{
// 		printf("Didnt check type\n");
// 		if(F)	
// 			freeTable(t2);
// 	}
//     else
//     {
//         printf ("Valid2-type checked +5\n");
//         count_test+=5;
//     }
        
// 	Table* t3 = createTable(1, 1, -1);
// 	if(t3 != NULL)
// 	{
// 		printf("Didnt check length\n");
// 		if(F)
// 			freeTable(t3);
// 	}
//     else
//     {
//         printf ("Valid3-length checked +5\n");
//         count_test+=5;   
//     }
// 	printf("-------------------------------------------------------\n");
// 	//Create Table
// 	if(CHECK_INT)
// 	{
// 		Table* t = createTable(4, INT_TYPE, 3);
// 		printf("***Create Table***\n");
// 		if(t == NULL)
//         {
//             printf("Error on CREATE\n");
//         }
//         else
//         {
//             printf ("(Type INT) table created +5\n");
//             count_test+=5;   
//         }
// 		printTable(t);
// 		printf("1-------------------------------------------------------\n");
// 		int x = 1;
// 		int y = 2;
// 		int z = 3;
// 		printf("***Add***\n");
// 		printf("New element index: %d\n", add(t, &y));
// 		printf("New element index: %d\n", add(t, &x));
// 		printf("New element index: %d\n", add(t, &x));
// 		printf("New element index: %d\n", add(t, &x));
// 		printTable(t);
// 		printf("2-------------------------------------------------------\n");
// 		printf("New element index: %d\n", add(t, &x));
// 		printTable(t);
// 		printf("3-------------------------------------------------------\n");
// 		printf("New element index: %d\n", add(t, &x));
// 		printf("New element index: %d\n", add(t, &x));
//         printf("New element index: %d\n", add(t, &x));
//         printTable(t);
//         printf("4-------------------------------------------------------\n");
//         printf("New element index: %d\n", add(t, &x));
//         printf("New element index: %d\n", add(t, &x));
//         printf("New element index: %d\n", add(t, &x));
//         printTable(t);
//         printf("5-------------------------------------------------------\n");
//         printf("New element index: %d\n", add(t, &x));
//         printf("New element index: %d\n", add(t, &x));
//         printf("New element index: %d\n", add(t, &x));
// 		printTable(t);
// 		printf("6-------------------------------------------------------\n");
// 		printf("***Search***\n");
// 		if(Test1)
// 		{
			
// 			if(search(t, NULL) != NULL){
// 				printf("Test1-Error on search\n");
//             }
//             else
//             {
//                 printf("Test1 - succeed +5\n");
//                 count_test+=5;
//             }
//         }
//         if(Test2)
//         {
// 			if(search(t, &x) == NULL && search(t, &y) == NULL)
//             {
// 				printf("Test2-Error on search, didn't find %d\n", x);
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test2 -succeed, found %d : +5\n",x);
//             }
//         }
//         if(Test4){
// 			if(search(t, &z) != NULL)
//             {
// 				printf("Test4-Error on search, found non existing element\n");
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test4 - succeed, +5\n"); // the z is not on list
//             }
// 		}
// 		printf("***Remove***\n");
// 		if(Test8)
// 		{
// 			if(removeObj(t, NULL) != -1){
// 				printf("Test8 - Error on remove\n"); //you are try delete null obj
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test8 - succeed +5\n");
//             }
//         }	
//         if(Test9)
//         {
// 			if(removeObj(t, &x) == -1){
// 				printf("Test9 - Error on remove\n");
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test9 - succeed, obj removed +5\n");
//             }
//         }	
//         printTable(t);
//          if(Test10)
//          {
// 			if(removeObj(t, &y) == -1){
// 				printf("Test10 - Error on remove\n");
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test10 - succeed, obj removed +5\n");
//             }
//         }
//         if(Test12)
//         {
// 			if(removeObj(t, &z) != -1){
// 				printf("Test12 - Error on remove\n"); // you are try delete obj of not in list
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test12 - succeed, +5\n"); // z is not in list
//             }
//         }	
//         printf("7-------------------------------------------------------\n");
// 			printTable(t);
		
// 		if(FREE_TABLE)
// 			freeTable(t);
// 	}
	
// 	printf("-------------------------------------------------------\n");
// 	//====================String====================	
// 	if(CHECK_STRING)
// 	{
// 		printf("******String Type******\n");			
// 		Table* tStr = createTable(4, STR_TYPE, 3);
// 		printf("***Create Table***\n");	
// 		if(tStr == NULL){
// 			printf("Error on CREATE\n");
//         }
//         else
//         {
//             printf ("(Type STRING) table created +5\n");
//             count_test+=5;   
//         }
//         printf("8-------------------------------------------------------\n");
// 		printTable(tStr);
//         char* a = "11";
// 		char* b = "22";
// 		char* c = "33";
// 		printf("***Add***\n");
// 		printf("New element index: %d\n", add(tStr, a));
// 		printf("New element index: %d\n", add(tStr, b));
// 		printf("New element index: %d\n", add(tStr, b));
// 		printf("New element index: %d\n", add(tStr, b));
// 		printf("9-------------------------------------------------------\n");
// 		printTable(tStr);
// 		printf("New element index: %d\n", add(tStr, b));
// 		printf("10-------------------------------------------------------\n");
// 		printTable(tStr);
// 		printf("New element index: %d\n", add(tStr, b));
// 		printf("New element index: %d\n", add(tStr, b));
//         printf("New element index: %d\n", add(tStr, b));
//         printf("11-------------------------------------------------------\n");
//         printTable(tStr);
//         printf("New element index: %d\n", add(tStr, b));
//         printf("New element index: %d\n", add(tStr, b));
//         printf("New element index: %d\n", add(tStr, b));
//         printf("12-------------------------------------------------------\n");
//         printTable(tStr);
//         printf("New element index: %d\n", add(tStr, b));
//         printf("New element index: %d\n", add(tStr, b));
//         printf("New element index: %d\n", add(tStr, b));
// 		printf("13-------------------------------------------------------\n");
// 		printTable(tStr);
// 		if(Test5)
// 		{
// 			printf("***Search***\n");
// 			if(search(tStr, NULL) != NULL){
// 				printf("Test5-Error on search\n"); //you are search for null obj
//             }
//             else
//             {
//                 printf("Test5 - succeed serch +5");
//                 count_test+=5;
//             }
//         }
// 		if(Test6)
// 		{
// 			if(search(tStr, a) == NULL && search(tStr, b) == NULL){
// 				printf("Test6-Error on search\n");
//             }
//             else
//             {
//                 printf("Test6 - succeed, found a && b : +5\n");
//                 count_test+=5;
//             }
//         }
// 		if(Test7)
// 		{
// 			if(search(tStr, c) != NULL){
// 				printf("Test7-Error on search\n");
//             }

//             else
//             {
//                 count_test+=5;
//                 printf("Test7 - succeed, found existing element +5\n");
//             }
// 		}
// 		if(Test11)
// 		{
// 			printf("***Remove***\n");
// 			if(removeObj(tStr, NULL) != -1){
// 				printf("Test11 -Error on remove\n"); //you are try to delete null obj
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test11 - succeed +5\n");
//             }
// 		}		
// 		if(Test13)
// 		{
// 			if(removeObj(tStr, a) == -1 && removeObj(tStr, b) == -1){
// 				printf("Test13 - Error on remove\n");
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test13 - succeed, obj removed +5\n");
//             }
//         }
//         if(Test14)
//         {
// 			if(removeObj(tStr, c) != -1){
// 				printf("Test14 - Error on remove\n");
//             }
//             else
//             {
//                 count_test+=5;
//                 printf("Test14 - succeed, obj removed +5\n");
//             }
//         }
//         printf("14-------------------------------------------------------\n");
// 			printTable(tStr);
		
// 		if(FREE_TABLE)
// 			freeTable(tStr);
// 	}
//     printf("***The grade is : %d ***\n",count_test); //the grade not include the Valgrind test, valgrind = 10 pts



// 	return 0;
// }