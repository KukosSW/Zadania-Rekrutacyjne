/**
 * Implement IList structure as a pseudo class.
 * IList contains values in a linked list (unsorted)
 *
 * 1. Implement constructor (new function), destructor (delete function) and insertion an element at the end (push_back function).
 *      To make this code simpler, lets assume that there is no deletion from the list
 * 2. Implement required getters like getting length, checking if the list is empty or not and getting the element from given index / position
 * 3. Write a few tests
 * 4. How fast is your implementation? Calculate time complexity of your algorithm using Big O notation.
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

typedef struct INode
{
    int val;
    struct INode* next;
} INode;

typedef struct IList
{
    /* Implement structure body */
} IList;

IList* ilist_new(void);
void ilist_delete(IList* il);
void ilist_push_back(IList* il, int val);

/* Add more required functions */

IList* ilist_new(void)
{
    /* Implement this function */
    return NULL;
}

void ilist_delete(IList* const il)
{
   /* Implement this function */
}

void ilist_push_back(IList* const il, const int val)
{
    /* Implement adding val at the end of the list */
}

int main(void)
{
    IList* il = ilist_new();

     /* Add all functions + tests */

    return 0;
}