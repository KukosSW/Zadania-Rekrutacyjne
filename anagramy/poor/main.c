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

static bool is_anagram(const char *a, const char *b);
static bool is_anagram(const char *a, const char *b)
{
    if (a == NULL || b == NULL)
        return false;

    const size_t a_len = strlen(a);
    const size_t b_len = strlen(b);

    if (a_len != b_len)
        return false;

    char *b_copy = malloc(sizeof(b_copy[0]) * b_len);
    if (b_copy == NULL)
        return false;

    memcpy(b_copy, b, sizeof(b_copy[0]) * b_len);

    for (size_t i = 0; i < a_len; ++i)
    {
        bool found = false;
        for (size_t j = 0; j < b_len; ++j)
            if (a[i] == b_copy[j])
            {
                found = true;
                b_copy[j] = '\0';
                break;
            }

        if (!found)
        {
            free(b_copy);
            return false;
        }
    }

    free(b_copy);
    return true;
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
