/**
 * 1. Design and implement get_combinations_le_100, which counts number of combinations consist of 2 elements
 *      such that their sum is <= 100
 *
 *      The function gets an array of type unsigned. There is no specific range of values.
 *      The Array can consist of any values of unsigend type.
 *      The combination is a pair of 2 numbers from 2 different places (array indexes).
 *      Please note that the combination is an unordered set. So {a, b} and {b, a} are counted as 1 combination.
 *
 *      Example:
 *      unsigned t[] = {0, 2, 0, 99};
 *
 *      We have following combinations (0 and 0 are counted as 2 different numbers, because they have different indexes in array t)
 *
 *      0 + 2, t[0] + t[1]
 *      0 + 0, t[0] + t[2]
 *      0 + 99, t[0] + t[3]
 *      2 + 0, t[1] + t[2]
 *      0 + 99, t[2] + t[3]
 *
 *      Result = 5
 *
 * 2. Write several unit tests.
 *
 * 3. Calculate time complexity of your algorithm using Big O notation.
 *
 * Show us your programming skills, style, knowledge of C features.
 *      Your code should be safe, readable, and fast (in terms of time complexity and new cpu architecture)
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

size_t get_combinations_le_100(const unsigned t[], size_t t_len);

size_t get_combinations_le_100(const unsigned t[const], const size_t t_len)
{
    /* Implement */
    return 0;
}

int main(void)
{
    /* Example */
    const size_t no_combinations = get_combinations_le_100((unsigned[]){0, 2, 0, 99}, 4); /* should be 5 */

    /* Add tests */

    return 0;
}
