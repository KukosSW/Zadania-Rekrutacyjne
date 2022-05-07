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

    size_t a_hist[255] = {0};
    size_t b_hist[255] = {0};

    for (size_t i = 0; i < a_len; ++i)
    {
        ++a_hist[(size_t)a[i]];
        ++b_hist[(size_t)b[i]];
    }

    const bool is_correct_angagram = memcmp(a_hist, b_hist, sizeof(a_hist)) == 0;

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
