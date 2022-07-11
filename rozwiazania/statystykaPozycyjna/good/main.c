/**
 * 1. Zaprojektuj i zaimplementuj funkcje get_n_largest, ktora znajdzie i zwroci nta najwieksza liczbe w tablicy
        (liczymy od 1, czyli max w tablicy to 1 najwieksza)
 *      Dla ulatwienia mozemy przyjac ze tablica skladac sie bedzie tylko z liczb dodatnich, ktore nie moga sie powtarzac
 *
 * 2. Napisz testy jednostkowe
 *
 * 3. Wyznacz zlozonosc asymptotyczna swojego rozwiazania w notacji duze O.
 *
 * Pokaz swoj styl programowania, pochwal sie znajomoscia dobrych metodyk oraz ficzerow jezyka C.
 *      Zadbaj o to aby Twoj kod byl bezpieczny, czytelny i szybki (wez pod uwage aspekty algorytmiczne jak i ficzery nowych cpu)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

unsigned get_n_largest(const unsigned arr[], size_t len, size_t n);

int cmp_unsigned(const void* a, const void* b);

int cmp_unsigned(const void* const a, const void* const b)
{
    return (int)(*(const unsigned *)b - *(const unsigned *)a);
}

unsigned get_n_largest(const unsigned arr[const], const size_t len, const size_t n)
{
    if (arr == NULL || len == 0 || n == 0 || n > len)
        return 0;

    unsigned *arr_copy = malloc(sizeof(*arr_copy) * len);
    if (arr_copy == NULL)
        return 0;

    memcpy(arr_copy, arr, sizeof(*arr) * len);
    qsort(arr_copy, len, sizeof(*arr_copy), cmp_unsigned);

    const unsigned n_largest = arr_copy[n - 1];

    free(arr_copy);

    return n_largest;
}

int main(void)
{
    // Liczby sa dodatnie, wiec jako blad mozemy zwracac 0
    assert(get_n_largest(NULL, 5, 1) == 0);
    assert(get_n_largest((unsigned[]){1, 2, 3}, 3, 0) == 0);
    assert(get_n_largest((unsigned[]){1, 2, 3}, 3, 100) == 0);

    const unsigned arr[] = {3, 6, 2, 8, 9, 1, 5, 7, 4};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    assert(get_n_largest(arr, arr_len, 1) == 9);
    assert(get_n_largest(arr, arr_len, 3) == 7);
    assert(get_n_largest(arr, arr_len, 5) == 5);
    assert(get_n_largest(arr, arr_len, 9) == 1);

    return 0;
}
