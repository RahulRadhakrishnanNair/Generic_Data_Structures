#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.h" // Own library created as a header file.

/* NOTE: This uses calloc for the declaration of a stack, this is due to the new type unable to support void.*/

class Stack{ // Class declaration of a dynamic stack, generic.
    private:
        void* stack; // Contains stack
        DATATYPE type; // Data type indication
        STRUCTURE structure;    // What structure it is (a stack)
        void* topPointer;   // Points at the top
        int size;  // Size of the stack
        int utilisedSize; // How many spaces have been used.

        bool isFull(){ // Checks if the stack is full, is private because it never needs to be checked due to being dynamic.
            if (utilisedSize >= size){
                return true;
            }    
            return false;
        }

    public:
        Stack(DATATYPE stackType){ // Constructor declaration to create an empty stack.
            this->stack = calloc(1, returnBytes(stackType)); // Allocating memory for a stack.
            null_check(stack);
            this->topPointer = stack;
            this->type = stackType; // Indicates the data type used for the stack.
            this->structure = STACK; // Indicates data structure, a stack.
            this->size = 1; // Starts off with a size of 1.
            this->utilisedSize = 0; // Starts empty.
        }

        bool isEmpty(){ // Checks if the stack is empty.
            if (utilisedSize == 0){
                return true;
            }
            return false;
        }

        void push(void* value){
            if (isFull() == true){
                size = size * 2; // Doubles the size
                stack = realloc(stack, returnBytes(type)); // reallocates the memory for the stack to contain double the amount of items.
                null_check(stack); // Checks if realloc fails.
            }

            topPointer = value;
            topPointer++;
        }

};