/**
 * 1. Design and implement function is_anagrams, which checks if 2 arguments are anagrams
 *      To make it simple, you can assume that arguments will be small letters
 *
 *      Anagrams are words contains the same letters but in different (or the same) permutation
 *      "ala" "laa" are anagrams
 *      "ala" "all" are not
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

bool is_anagrams(const char* const str1, const char* const str2);

bool is_anagrams(const char* const str1, const char* const str2)
{
    /* Implement */
    return false;
}

int main(void)
{
    /* Examples */
    const bool b1 = is_anagrams("ala", "laa"); // should be true
    const bool b2 = is_anagrams("ala", "aal"); // should be true
    const bool b3 = is_anagrams("ala", "lla"); // should be false

    /* Add tests  */

    return 0;
}
