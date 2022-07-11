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

size_t get_max_index(const unsigned arr[], size_t len);

size_t get_max_index(const unsigned arr[const], const size_t len)
{
    if (arr == NULL || len == 0)
        return (size_t)-1;

    size_t max_index = 0;
    for (size_t i = 1; i < len; ++i)
        if (arr[i] > arr[max_index])
            max_index = i;

    return max_index;
}

unsigned get_n_largest(const unsigned arr[const], const size_t len, const size_t n)
{
    if (arr == NULL || len == 0 || n == 0 || n > len)
        return 0;

    unsigned *arr_copy = malloc(sizeof(*arr_copy) * len);
    if (arr_copy == NULL)
        return 0;
    memcpy(arr_copy, arr, sizeof(*arr) * len);

    for (size_t i = 0; i < n - 1; ++i)
        arr_copy[get_max_index(arr_copy, len)] = 0;

    const unsigned n_largest = arr_copy[get_max_index(arr_copy, len)];

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
