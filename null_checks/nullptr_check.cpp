#include <iostream>
#include "datastructures.h" // Own library created as a header file.

// C++ version for null pointer handling, used for CPP_STYLE_STRINGS

bool nullptr_check(void* dynamicallyAllocatedMemory){ // Checks if the memory allocated is equal to NULL
    if (dynamicallyAllocatedMemory == nullptr){       // If the memory is equal to NULL, then it returns false and everything is stopped.
        return false;
        exit(1);
    }
    else{                                             // Otherwise, nothing is wrong and the function returns true.
        return true;
    }
}
