#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/*

Dana jest tablica liczb unsigned int, z calego ich przedzialu 0, 2^32 - 1.
Napisz program ktory zliczy wszystkie kombinacje liczb a, b z tej tablicy, ze a + b <= 100;

Przykład:
unsigned t[] = {0, 2, 0, 99};
mamy
0 + 2, t[0] + t[1]
0 + 0, t[0] + t[2]
0 + 99, t[0] + t[3]
2 + 0, t[1] + t[2]
0 + 99, t[2] + t[3]
Zatem wynik to 5.

*/
static size_t upper_bound(const unsigned t[], size_t t_len, unsigned key);
static int unsigned_cmp(const void* a, const void* b);
static size_t count_combination_le_100(const unsigned t[], size_t t_len);

static size_t upper_bound(const unsigned t[], size_t t_len, unsigned key)
{
    size_t left = 0;
    size_t right = t_len;

    while (left < right)
    {
        const size_t middle = (right - left) / 2 + left;
        if (t[middle] < key)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}

static int unsigned_cmp(const void* a, const void* b)
{
    const unsigned _a = *(const unsigned *)a;
    const unsigned _b = *(const unsigned *)b;

    return (int)(_a - _b);
}

static size_t count_combination_le_100(const unsigned t[], size_t t_len)
{
    if (t == NULL)
        return 0;

    if (t_len == 0)
        return 0;


    unsigned* t_copy = malloc(sizeof(t_copy[0]) * t_len);
    if (t_copy == NULL)
        return 0;

    // memcpy(t_copy, t, sizeof(t_copy[0]) * t_len);
    size_t t_index = 0;
    for (size_t i = 0; i < t_len; ++i)
        if (t[i] <= 100)
            t_copy[t_index++] = t[i];

    t_len = t_index;
    qsort(t_copy, t_len, sizeof(t_copy[0]), unsigned_cmp);

    // size_t combination_counter = 0;
    // for (size_t i = 0; i < t_len; ++i)
    //     if (t_copy[i] <= 100 / 2)
    //         for (size_t j = i + 1; j < t_len; ++j)
    //             if (t_copy[j] > 100)
    //                 break;
    //             else if (t_copy[i] + t_copy[j] <= 100)
    //                 ++combination_counter;

    size_t combination_counter = 0;
    for (size_t i = 0; i < t_len; ++i)
        if (t_copy[i] <= 100 / 2)
        {
            const size_t pos = upper_bound(&t_copy[i], t_len - i, 100 - t_copy[i]) - 1 + i;
            combination_counter += pos - i;
        }

    free(t_copy);
    return combination_counter;
}

int main(void)
{
    assert(count_combination_le_100(NULL, 0) == 0);
    assert(count_combination_le_100((unsigned[]){1, 2, 3}, 0) == 0);
    assert(count_combination_le_100(NULL, 10) == 0);
    assert(count_combination_le_100((unsigned[]){0, 2, 0, 99}, 4) == 5);
    assert(count_combination_le_100((unsigned[]){110, 112, 110, 1199}, 4) == 0);
    assert(count_combination_le_100((unsigned[]){111, 0, 2, 222, 0, 99, 333}, 6) == 5);
    assert(count_combination_le_100((unsigned[]){0, 2, 0, 99, UINT_MAX}, 5) == 5);

    return 0;
}
