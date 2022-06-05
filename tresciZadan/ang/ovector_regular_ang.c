/**
 * Implement OVector structure as a pseudo class.
 * OVector contains dynamic array of any type.
 * The same code should works on int, char, double, char* ...
 * When OVector is creating user is passing size of element stored in OVector, i.e. sizeof(int)
 *
 * At the beginning an array inside OVector has length equals K (choose K by yourself),
 * when the array if full, you need to resize the array with new length K' (ofc K' > K).
 * User should not see any change. It means that user is working on OVector strucutre and dont care about field inside.
 * You need to design proper encapsulation of OVector code to hide changes i.e getters, other functions ...
 *
 * 1. Implement constructor (new function), destructor (delete function), insertion an element (insert function)
 *      and deletion (erase function) which deleting element from given index.
 *      To make this code simpler, lets assume that the insert function adding new element at the end of the array
 * 2. Implement required getters like getting length, element from index
 * 3. Write a few tests
 * 4. How fast is your implementation? Calculate time complexity of your algorithm using Big O notation.
 *      You can use  amortized analysis.
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

typedef struct OVector
{
    /* Implement strucute body */
} OVector;

OVector* OVector_new(size_t elem_size);
void OVector_delete(OVector* ov);
void OVector_insert(OVector* ov, const void* val);
void OVector_erase(OVector* ov, size_t index);

/* Add more required functions */

OVector* OVector_new(const size_t elem_size)
{
    /* Implement strucute body */
    return NULL;
}

void OVector_delete(OVector* const iv)
{
    /* Implement this function */
}

void OVector_insert(OVector* const iv, const void* const val)
{
    /* Implement this function */
}

void OVector_erase(OVector* const ov, const size_t index)
{
    /* Implement this function */
}

int main(void)
{
    OVector* ov = OVector_new(sizeof(int));

    /* Add all functions + tests */

    return 0;
}
