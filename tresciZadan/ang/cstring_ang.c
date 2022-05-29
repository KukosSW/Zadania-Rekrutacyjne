/**
 * Implement CString structure as a pseudo class
 * It will be a wrapper to primitive char* type
 * Your implementation should cover both stack variables (char str[] = "Test")
 *      and const literals ("Test")
 *
 * You need to implement all functionalities listed below and fulfill all of the resrictions / conditions
 * 1. The constructor (cstring_new) can work in any time complexity
 * 2. The function which returns length of the char* wrapped into CString have to work in O(1)
 * 3. The function which returns single char (from index, counting from 0) have to work in O(1)
 * 4. The function which changes single char (from index, counting from 0) to new char, have to work in O(1)
 * 5. The function which returns entire string have to work in O(1).
 *      You need to use C mechanism to prevent user from changing string outside the functions.
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

typedef struct CString
{
    /* Implement strucute body */
} CString;

CString* cstring_new(const char* str);

/* Add more required functions */

CString* cstring_new(const char* const str)
{
    /* Implement this function */
    return NULL;
}

int main(void)
{
    CString* cs = cstring_new("Alice and Bob are playing the video game");

    /* Add all functions + tests */

    return 0;
}
