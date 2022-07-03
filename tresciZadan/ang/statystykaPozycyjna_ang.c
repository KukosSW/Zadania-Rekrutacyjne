/**
 * 1. Design and implement function get_n_largest, which finds nth greatest number from array and returns this number
 *     (We are counting from 1, so the maximum number is the 1st largest)
 *     To make it simpler, we can assume that array will contain only positive, unique numbers
 *
 * 2. Write several unit tests.
 *
 * 3. Calculate time complexity of your algorithm using Big O notation.
 *
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

unsigned get_n_largest(const unsigned arr[], size_t len, size_t n);

unsigned get_n_largest(const unsigned arr[const], const size_t len, const size_t n)
{
    /* Implement */
    return 0;
}

int main(void)
{
    /* Examples */
    const unsigned arr[] = {3, 6, 2, 8, 9, 1, 5, 7, 4};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    assert(get_n_largest(arr, arr_len, 1) == 9);
    assert(get_n_largest(arr, arr_len, 3) == 7);
    assert(get_n_largest(arr, arr_len, 5) == 5);
    assert(get_n_largest(arr, arr_len, 9) == 1);

    /* Add tests  */

    return 0;
}

