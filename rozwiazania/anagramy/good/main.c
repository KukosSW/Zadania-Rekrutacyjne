#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/*

1) Napisz program, który stwierdzi czy 2 słowa (tylko małe litery) są anagramami.
Anagram to słowo powstałe przez przestawienie liter. Nie wolno dodać litery, odjąć, można tylko je permutować.

Przykład:
"ala" "laa" jest ok
"ala" "all" nie ok

2) Napisz 3-4 testy jednostkowe do zadania. Możesz użyć funkcji assert.

3) Wyznacz złożoność rozwiązania, możesz użyć do tego dowolnej notacji asymptotycznej np duże O lub duże Omega.
Czy potrafisz zrobić to lepiej?

*/

static int cmp_char(const void* a, const void* b);
static bool is_anagram(const char *a, const char *b);

static int cmp_char(const void* a, const void* b)
{
    const char _a = *(const char *)a;
    const char _b = *(const char *)b;

    return _a - _b;
}

static bool is_anagram(const char *a, const char *b)
{
    if (a == NULL || b == NULL)
        return false;

    const size_t a_len = strlen(a);
    const size_t b_len = strlen(b);

    if (a_len != b_len)
        return false;

    char *a_copy = malloc(sizeof(a_copy[0]) * a_len);
    if (a_copy == NULL)
        return false;
    memcpy(a_copy, a, sizeof(a_copy[0]) * a_len);

    char *b_copy = malloc(sizeof(b_copy[0]) * b_len);
    if (b_copy == NULL)
    {
        free(a_copy);
        return false;
    }
    memcpy(b_copy, b, sizeof(b_copy[0]) * b_len);

    qsort(a_copy, a_len, sizeof(a_copy[0]), cmp_char);
    qsort(b_copy, b_len, sizeof(b_copy[0]), cmp_char);

    const bool is_correct_angagram = memcmp(a_copy, b_copy, sizeof(b_copy[0]) * b_len) == 0;

    free(a_copy);
    free(b_copy);

    return is_correct_angagram;
}

int main(void)
{
    assert(is_anagram("aqweqweqla", "laakqwjeklwqjekqwlkjelk") == false);
    assert(is_anagram("ala", "laa") == true);
    assert(is_anagram("ala", "all") == false);
    assert(is_anagram("ala", "ala") == true);
    assert(is_anagram(NULL, NULL) == false);

    return 0;
}
