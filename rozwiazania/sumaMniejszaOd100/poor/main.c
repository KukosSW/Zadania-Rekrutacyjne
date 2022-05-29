#include <stdio.h>
#include <assert.h>
#include <limits.h>

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

static size_t count_combination_le_100(const unsigned t[], size_t t_len);

static size_t count_combination_le_100(const unsigned t[], size_t t_len)
{
    if (t == NULL)
        return 0;

    // BIN[t_len, 2]
    // SUM[0, t_len - 1, i]
    // n * (n - 1) / 2 == 1/2n^2 - 1/2n
    // O(n^2)
    size_t combination_counter = 0;
    for (size_t i = 0; i < t_len; ++i)
        for (size_t j = i + 1; j < t_len; ++j)
            if (t[i] <= 100 && t[j] <= 100 && t[i] + t[j] <= 100)
                ++combination_counter;

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
