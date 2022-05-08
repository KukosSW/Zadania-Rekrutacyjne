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

    if (t_len == 0)
        return 0;

    size_t hist[101] = {0};
    for (size_t i = 0; i < t_len; ++i)
        if (t[i] <= 100)
            ++hist[t[i]];

    size_t combination_counter = 0;
    for (size_t i = 0; i <= 100 / 2; ++i)
    {
        if (hist[i] > 1)
            combination_counter += (hist[i] * (hist[i] - 1)) / 2;

        /* Z kadym kolejnym tworzymy n * m kombinacji (kazdy z kazdym) */
        for (size_t j = i + 1; j <= 100 - i; ++j)
            combination_counter += hist[i] * hist[j];
    }

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
