/*=====================================================================================================================================*/
/*=====================================================================================================================================*/
/*=======================================--------------------------------------------------------======================================*/
/*==================================---------------------------Tal Randi------------------------------=================================*/
/*================================-----------------------------315633503--------------------------------===============================*/
/*==================================------------------------------Ex1--------------------------------==================================*/
/*=======================================--------------------------------------------------------======================================*/
/*=====================================================================================================================================*/
/*=====================================================================================================================================*/

#include "GenericHashTable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**Private function :
 *This function gets a table and return it on doubled size
 **/
void doubleTheTableSize(Table* table)
{
    //Validation check
    if(!table)
        return;
 
    int new_size = table->current_size*2;
    int i = 0;
    Object** temp = (Object**)malloc(sizeof(Object*)*new_size);
    if(!temp)
    {
        printf("malloc failed in doubleTheTableSize\n");
        return;
    }
    //set null in all temp
    for(; i < new_size ; i++)
        temp[i] = NULL;
    
    //Update the pointers from index i to i*2
    for(i = table->current_size - 1; i >= 0 ; i--)
        temp[i*2] = table->arr[i];

    free(table->arr);
    
    table->arr = temp;

    //Update data members of table
    table->current_size = new_size;
    table->ratio = (table->current_size)/(table->original_size);
}

//This function gets size, type, and list length of a new required table, and return a pointer to is.
Table* createTable(int size, int dType, int listLength)
{
    //Validation check
    if(size <= 0 || (dType != 0 && dType != 1) || listLength <=0)
    {
        printf("There is at least one invalid parameter; createTable failed !\n");
        return NULL;
    }
    Table* table = (Table*)malloc(sizeof(Table));
    if(!table)
    {
        printf("malloc failed in createTable\n");
        return NULL;
    }
    //Set the data members
    table->list_length = listLength;
    table->type = dType;
    table->current_size = size;
    table->original_size = size;
    table->ratio = (table->current_size)/(table->original_size);

    table->arr = (Object**)malloc(sizeof(Object*)*size);
    if(!table->arr)
    {
        printf("malloc failed in createTable\n");
        return NULL;
    }
    int i = 0;
    //Sets null in all cells
    for(; i < size ; i++)
        table->arr[i] = NULL;
    
    return table;
}

//This function gets a table and free all its resources
void freeTable(Table* table)
{
    //Validation check
    if(!table)
        return;

    Object* pointer1 = NULL;
    Object* pointer2 = NULL;
    int i = 0;
    //Free all cells in arr
    for(; i < table->current_size ; i++)
    {
        if(table->arr[i])
        {
            pointer1 = table->arr[i];
            //Free all element in specific list
            while(pointer1)
            {
                pointer2 = pointer1->next;
                freeObject(pointer1);
                pointer1 = pointer2;
            }
        }
    }
    free(table->arr);
    free(table);
}

/*This function gets a table and data, and insert the data to the table 
by creating a new object which its data are pointed to the parameter data
*/
int add(Table* table, void* data)
{
    //Validation check
    if(!table || !data) 
    {
        printf("There at least one invalid parameter; add function failed !\n");
        return -1;
    }
    int object_counter = 0;
    int index = 0;
    Object* pointer = NULL;
    
    //int case
    if(table->type == INT_TYPE)
    {
        index = table->ratio*intHashFun(data, table->original_size);
        pointer = table->arr[index];          
        int* temp = (int*)malloc(sizeof(int));
        if(!temp)
        {
            printf("malloc failed in add function\n");
            return -1;
        }
        *temp = *(int*)data;
        if(!pointer)
            table->arr[index] = createObject(temp);
        //pointer is not null
        else
        {
            for(int i = index ; i < table->ratio+index ; i++)
            {
                pointer = table->arr[i]; 
                if(!pointer)
                {
                    table->arr[i] = createObject(temp);
                    return i;
                }
                object_counter++;
                while(pointer->next)
                {
                    object_counter++;
                    pointer = pointer->next;
                }
                //There is free place on the linked list
                if(object_counter < table->list_length)
                {
                    pointer->next = createObject(temp);
                    return i;
                }
                else if(i == table->ratio+index - 1 && object_counter == table->list_length)
                {
                    doubleTheTableSize(table);
                    free(temp);
                    return add(table,data);
                }
                else
                {
                    object_counter = 0;
                }
            }
        }
    }
    //String case
    else if(table->type == STR_TYPE)
    {
        index = table->ratio*strHashFun(data, table->original_size);
        pointer = table->arr[index];   
        int size_of_str = strlen((char*)data);
        char* temp = (char*)malloc(sizeof(char)*size_of_str + 1);
        if(!temp)
        {
            printf("malloc failed in add function\n");
            return -1;
        }
        strcpy(temp, data);
        if(!pointer)
            table->arr[index] = createObject(temp);
        //pointer is not null
        else
        {
            for(int i = index ; i < table->ratio+index ; i++)
            {
                pointer = table->arr[i]; 
                if(!pointer)
                {
                    table->arr[i] = createObject(temp);
                    return i;
                }
                object_counter++;
                while(pointer->next)
                {
                    object_counter++;
                    pointer = pointer->next;
                }
                //There is free place on the linked list
                if(object_counter < table->list_length)
                {
                    pointer->next = createObject(temp);
                    return i;
                }
                else if(i == table->ratio+index - 1 && object_counter == table->list_length)
                {
                    doubleTheTableSize(table);
                    free(temp);
                    return add(table,data);
                }
                else
                {
                    object_counter = 0;
                }
            }   
        }
    }
    return index; 
}

/**
This function gets a table and data,
and return a pointer to an object which its data equal to the parameter data 
*/
Object* search(Table* table, void* data)
{   
    //Validation check
    if(!table || !data)
    {
        printf("The table or data is empty\n");
        return NULL;
    }
    Object* pointer;
    //int case
    if(table->type == INT_TYPE)
    {
        int* a = (int*)data;
        int* b;
        //Search for the specific element which its data equals to the data parameter
        for(int i = 0 ; i < table->current_size ; i++)
        {
            pointer = table->arr[i];
            while(pointer)
            {
                b = (int*)pointer->data;
                if(*a == *b)
                {
                    return pointer;
                }
                pointer = pointer->next;
            }
        }
    }
    //string case
    else if(table->type == STR_TYPE)
    {
        char* a = (char*)data;
        char* b;
        //Search for the specific element which its data equals to the data parameter
        for(int i = 0 ; i < table->current_size ; i++)
        {
            pointer = table->arr[i];
            while(pointer)
            {
                b = (char*)pointer->data;
                if(strcmp(a,b) == 0)
                {
                    return pointer;
                }
                pointer = pointer->next;
            }
        }
    }
    return NULL;
}

/*This function gets a table and data, and remove the object in the table
which its data equal to the data of the parameter.
*/
int removeObj(Table* table, void* data)
{
    //Validation check
    if(!table || !data)
    {
        printf("There at least one invalid paraneter; removeObj failed!\n");
        return -1;
    }
    int index = 0;;
    int result = 0; 
    int i = 0;
    Object* pointer = NULL;
    Object* prev = NULL;

    //int csae
    if(table->type == INT_TYPE)
        index = table->ratio*intHashFun((int*)data, table->original_size);
    //string case
    else if(table->type == STR_TYPE)
        index = table->ratio*strHashFun((char*)data, table->original_size);

    for(i = index ; i < index+table->ratio ; i++)
    {
        //There is some element in this cell
        if(table->arr[i])
        {
            pointer = table->arr[i];
            prev = pointer;
                
            while(pointer)
            {   
                if(table->type == INT_TYPE)
                    result = isEqual(INT_TYPE,pointer->data,data);
        
                else if(table->type == STR_TYPE)
                    result = isEqual(STR_TYPE,pointer->data,data); 
                //Found the element to remove
                if(result == 0)
                {
                    //First node
                    if(pointer == prev) 
                    {
                        if(!(pointer->next)) // only one node on the list
                        {
                            table->arr[i] = NULL;
                            freeObject(pointer);
                            return i;
                        }
                        else  
                        {
                            table->arr[i] = table->arr[i]->next;   
                            freeObject(pointer);
                            return i;
                        }
                    }
                    //Last node
                    else if(pointer != prev && pointer->next == NULL)
                    {
                        prev->next = NULL;
                        freeObject(pointer);
                        return i;
                    }
                    //Node is in the middle
                    else
                    {
                        prev->next = pointer->next;
                        freeObject(pointer);
                        return i;
                    }
                }
                //Element not eaual to this node
                else
                {
                    if(pointer == prev)
                        pointer = pointer->next;
                    else
                    {
                        prev = pointer;
                        pointer = pointer->next;
                    }                       
                }
            }
        }
    }
    return -1;       
}

/*This function gets a table and print it in a linked list format,
while each array cell is a start of linked list
*/
void printTable(Table* table)
{
    //Validation check
    if(!table)
        return;
        
    int i = 0 ;
    int size = table->current_size ;
    Object* pointer = NULL;

    for( ; i < size ; i++)
    {
        //index printing
        printf("[%d]\t",i);
        if(table->arr[i])
        {
            pointer = table->arr[i];
            //Objects printing
            while(pointer)
            {
                //int case
                if(table->type == INT_TYPE)
                    printf("%d\t-->\t", *((int*)pointer->data));
                //string case
                else if(table->type == STR_TYPE)
                    printf("%s\t-->\t", (char*)pointer->data);
                    
                pointer = pointer->next;
            }
        }
        printf("\n");
    }
}

//This function gets a generic data and create a new node object
Object* createObject(void* data)
{
    //Validation check
    if(!data)
    {
        printf("invalid data\n");
        return NULL;
    }
    Object* object = (Object*)malloc(sizeof(Object));
    if(!object)
    {
        printf("malloc failed in createObject\n");
        return NULL;
    }
    object->data = data;
    object->next = NULL;
    return object;
}
//The function gets an object, and free it's allocated memory
void freeObject(Object* obj)
{
    if(!obj)
    {
        printf("invalid object\n");
        return;
    }
    free(obj->data);
    free(obj);
}

//This function checks if two generic variables are equals
int isEqual(int type, void* data1, void* data2)
{
    //Validation check
    if((type < 0 && type > 1) || !data1 || !data2)
    {
        printf("There at least one invalid parameter; isEqual failed !\n");
        return -1;
    }
    //int case
    if(type == INT_TYPE)
    {
        int* a = (int*)(data1);
        int* b = (int*)(data2);
        if(*a == *b)
            return 0;
    }
    //string case
    else if(type == STR_TYPE)
    {
        char* a = (char*)(data1);
        char* b = (char*)(data2);
        return strcmp(a,b);
    }
    //Any other case
    return -1;
}

//The integer hash function
int intHashFun(int* key, int origSize)
{
    //Validation check
    if(origSize == 0)
        return -1;

    int r = *(key) % origSize;
    return r < 0 ? r + origSize : r;
    
}

//The String hash function
int strHashFun(char* key, int origSize)
{
    int sum_of_ascii = 0;
    int index = 0;
    while(key[index] != '\0')
    {
        sum_of_ascii += key[index];
        index++;
    }
    return sum_of_ascii%origSize;
}