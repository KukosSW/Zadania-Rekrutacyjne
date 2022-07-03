/**
 * Implement IVector structure as a pseudo class.
 * IVector contains dynamic array of integers. It works similar to std::vector<int> from C++.
 *
 * At the beginning an array inside IVector has length equals K (choose K by yourself),
 * when the array if full, you need to resize the array with new length K' (ofc K' > K).
 * User should not see any change. It means that user is working on IVector strucutre and dont care about field inside.
 * You need to design proper encapsulation of IVector code to hide changes i.e getters, other functions ...
 *
 * 1. Implement constructor (new function), destructor (delete function) and insertion an element (insert function).
 *      To make this code simpler, lets assume that there is no deletion and the insert function adding new element at the end of the array
 * 2. Implement required getters like getting length, element from index
 * 3. Write a few tests
 * 4. How fast is your implementation? Calculate time complexity of your algorithm using Big O notation.
 *      You can use  amortized analysis.
 * 5. Design and implement new constructor, which can create IVector from set of elements.
 *      i.e. IVector* iv = ivector_new_vals(5, 1, 2, 3, 4, 5) //  5 integers: {1, 2, 3, 4, 5}
 *      i.e. IVector* iv = ivector_new_vals(1, 2, 3, 4, 5) // harder one, creating Ivector without number of elements
 *      i.e. ... you can use your own idea, important thing is, that user should not create additional variable i.e array to pass integers into function
 *
 * You need to test all of your functions.
 * Show us your programming skills, style, knowledge of C features.
 *      Your code should be safe, readable, and fast (in terms of time complexity and new cpu architecture)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

typedef struct IVector
{
    /* Implement strucute body */
} IVector;

IVector* ivector_new(void);
void ivector_delete(IVector* iv);
void ivector_insert(IVector* iv, int val);

/* Add more required functions */

IVector* ivector_new(void)
{
    /* Implement this function */
    return NULL;
}

void ivector_delete(IVector* const iv)
{
    /* Implement this function */
}

void ivector_insert(IVector* const iv, const int val)
{
    /* Implement this function */
}

int main(void)
{
    IVector* iv = ivector_new();

    /* Add all functions + tests */

    return 0;
}
