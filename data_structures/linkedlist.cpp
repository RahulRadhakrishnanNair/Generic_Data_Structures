#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.

typedef struct LinkedList LinkedList; // Defining the name for the linked list.
typedef LinkedList* ll_ptr;           // Defining the name for a single pointer for a linked list.

struct LinkedList{           // Linked List struct definition (singly)
    void* val;               // Void pointer to pass any data type, generic.
    ll_ptr next;             // Pointer to the next value in the linked list.
    DATATYPE type;           // Type of data being passed towards the linked list.
    STRUCTURE structure;     // Type of data structure, will always be assigned to linked list enum.
};

ll_ptr initLinkedList (size_t size, DATATYPE type){ // Initalisation of a Linked List. Time complexity O(n), space complexity O(n).
    ll_ptr head = NULL; // Declaration of head and tail
    ll_ptr tail = NULL;

    for (size_t i = 0; i < size; i++){
        ll_ptr newNode = (ll_ptr)calloc(sizeof(LinkedList), 1); // Using calloc to allocate memory for a node.
        newNode->structure = LINKEDLIST;
        newNode->next = NULL;
        switch (type){  // Switch case used to assign a datatype enum to the linked list
            case (SIGNED_INT):{
                newNode->type = SIGNED_INT;
                newNode->val = (int*)calloc(sizeof(int), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%d", (int*)(&newNode->val));
                break;
            }
            case (UNSIGNED_INT):{
                newNode->type = UNSIGNED_INT;
                newNode->val = (unsigned int*)calloc(sizeof(unsigned int), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%u", (unsigned int*)(&newNode->val));
                break;
            }
            case (CHAR):{
                newNode->type = CHAR;
                newNode->val = (char*)calloc(sizeof(char), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%c", (char*)(&newNode->val));
                break;
            }
            case (SIGNED_CHAR):{
                newNode->type = SIGNED_CHAR;
                newNode->val = (signed char*)calloc(sizeof(signed char), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%d", (signed char*)(&newNode->val));
                break;
            }
            case (UNSIGNED_CHAR):{
                newNode->type = UNSIGNED_CHAR;
                newNode->val = (unsigned char*)calloc(sizeof(unsigned char), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%u", (unsigned char*)(&newNode->val));
                break;
            }
            case (SIGNED_SHORT):{
                newNode->type = SIGNED_SHORT;
                newNode->val = (signed short*)calloc(sizeof(signed short), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%hd", (signed short*)(&newNode->val));
                break;
            }
            case (UNSIGNED_SHORT):{
                newNode->type = UNSIGNED_SHORT;
                newNode->val = (unsigned short*)calloc(sizeof(unsigned short), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%hu", (unsigned short*)(&newNode->val));
                break;
            }
            case (STRING):{
                // Necessary info goes here...
            }
            case (CPP_STYLE_STRING):{
                newNode->type = CPP_STYLE_STRING;
                newNode->val = (std::string*)calloc(sizeof(std::string), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                //String input goes here...
                break;
            }
            case (FLOAT):{
                newNode->type = FLOAT;
                newNode->val = (float*)calloc(sizeof(float), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%f", (float*)(&newNode->val));
                break;
            }
            case (DOUBLE):{
                newNode->type = DOUBLE;
                newNode->val = (double*)calloc(sizeof(double), 1);
                printf("Input value %zu/%zu: ", i+1, size);
                scanf("%f", (double*)(&newNode->val));
                break;
            }    
        }
        if (head = NULL){ // Links head to the node if the head is empty
            head = newNode;
        }
        else{ // The next node of the tail become newNode
            tail->next = newNode;
        }
        tail = newNode; // The tail becomes newNode
    }

    return head; // Returns completed list
}

void print_linkedlist(ll_ptr list){ // Printing a Linked List. Time complexity O(n), space complexity O(1).
    ll_ptr temp = list;  // Linked List pointer points to the list, to avoid changing node order.
    while (temp != NULL || temp != nullptr){ // Loops through the list, until it reaches the terminating pointer (NULL or nullptr).
        switch(temp->type){                  // Type casting based on the datatype of the list, enum.
            case(SIGNED_INT):{
                printf("%d -> ", *(signed int*)(temp->val));
                break;
            }
            case(UNSIGNED_INT):{
                printf("%u -> ", *(unsigned int*)(temp->val));
                break; 
            }
            case(CHAR):{
                printf("%c -> ", *(char*)(temp->val));
                break;
            }
            case(SIGNED_CHAR):{
                printf("%d -> ", *(signed char*)(temp->val));
                break;
            }
            case(UNSIGNED_CHAR):{
                printf("%u -> ", *(unsigned char*)(temp->val));
                break;
            }
            case(SIGNED_SHORT):{
                printf("%hd -> ", *(signed short*)(temp->val));
                break;
            }
            case(UNSIGNED_SHORT):{
                printf("%hu -> ", *(unsigned short*)(temp->val));
                break;
            }
            case(STRING):{
                // Code goes here...
                break;
            }
            case(CPP_STYLE_STRING):{
                std::cout << *(std::string*)(temp->val) << " -> ";
                break;
            }
            case(BOOLEAN):{
                printf("%d -> ", *(bool*)(temp->val));
                break;
            }
            case(FLOAT):{
                printf("%f -> ", *(float*)(temp->val));
                break;
            }
            case(DOUBLE):{
                printf("%f -> ", *(double*)(temp->val));
                break;
            }
        }
        temp = temp->next;  // Goes to the next node.
    }
    printf("NULLPTR."); // Signifies the end of the list.
}

void insert_element_linkedlist(ll_ptr* list){ // Inserts an element at the head of the Linked List. Time complexity O(1), space complexity O(n).
    ll_ptr newNode = (LinkedList*)calloc(sizeof(LinkedList), 1);
    newNode->structure = LINKEDLIST;
    newNode->type = (*list)->type;
    switch (newNode->type){  // Switch case used to assign a datatype enum to the linked list
            case (SIGNED_INT):{
                newNode->type = SIGNED_INT;
                newNode->val = (int*)calloc(sizeof(int), 1);
                printf("Input value: ");
                scanf("%d", (int*)(&newNode->val));
                break;
            }
            case (UNSIGNED_INT):{
                newNode->type = UNSIGNED_INT;
                newNode->val = (unsigned int*)calloc(sizeof(unsigned int), 1);
                printf("Input value: ");
                scanf("%u", (unsigned int*)(&newNode->val));
                break;
            }
            case (CHAR):{
                newNode->type = CHAR;
                newNode->val = (char*)calloc(sizeof(char), 1);
                printf("Input value: ");
                scanf("%c", (char*)(&newNode->val));
                break;
            }
            case (SIGNED_CHAR):{
                newNode->type = SIGNED_CHAR;
                newNode->val = (signed char*)calloc(sizeof(signed char), 1);
                printf("Input value: ");
                scanf("%d", (signed char*)(&newNode->val));
                break;
            }
            case (UNSIGNED_CHAR):{
                newNode->type = UNSIGNED_CHAR;
                newNode->val = (unsigned char*)calloc(sizeof(unsigned char), 1);
                printf("Input value: ");
                scanf("%u", (unsigned char*)(&newNode->val));
                break;
            }
            case (SIGNED_SHORT):{
                newNode->type = SIGNED_SHORT;
                newNode->val = (signed short*)calloc(sizeof(signed short), 1);
                printf("Input value: ");
                scanf("%hd", (signed short*)(&newNode->val));
                break;
            }
            case (UNSIGNED_SHORT):{
                newNode->type = UNSIGNED_SHORT;
                newNode->val = (unsigned short*)calloc(sizeof(unsigned short), 1);
                printf("Input value: ");
                scanf("%hu", (unsigned short*)(&newNode->val));
                break;
            }
            case (STRING):{
                // Necessary info goes here...
            }
            case (CPP_STYLE_STRING):{
                newNode->type = CPP_STYLE_STRING;
                newNode->val = (std::string*)calloc(sizeof(std::string), 1);
                printf("Input value: ");
                //String input goes here...
                break;
            }
            case (FLOAT):{
                newNode->type = FLOAT;
                newNode->val = (float*)calloc(sizeof(float), 1);
                printf("Input value: ");
                scanf("%f", (float*)(&newNode->val));
                break;
            }
            case (DOUBLE):{
                newNode->type = DOUBLE;
                newNode->val = (double*)calloc(sizeof(double), 1);
                printf("Input value: ");
                scanf("%f", (double*)(&newNode->val));
                break;
            }    
        }
    newNode->next = *list;
}